let s:asciiart = [
			\"        :::      ::::::::",
			\"      :+:      :+:    :+:",
			\"    +:+ +:+         +:+  ",
			\"  +#+  +:+       +#+     ",
			\"+#+#+#+#+#+   +#+        ",
			\"     #+#    #+#          ",
			\"    ###   ########.fr    "
			\]

let s:start		= '/*'
let s:end		= '*/'
let s:fill		= '*'
let s:length	= 80
let s:margin	= 5

let s:types		= {
			\'\.c$\|\.h$\|\.cc$\|\.hh$\|\.cpp$\|\.hpp$\|\.php':
			\['/*', '*/', '*'],
			\'\.htm$\|\.html$\|\.xml$':
			\['<!--', '-->', '*'],
			\'\.js$':
			\['//', '//', '*'],
			\'\.tex$':
			\['%', '%', '*'],
			\'\.ml$\|\.mli$\|\.mll$\|\.mly$':
			\['(*', '*)', '*'],
			\'\.vim$\|\vimrc$':
			\['"', '"', '*'],
			\'\.el$\|\emacs$':
			\[';', ';', '*'],
			\'\.f90$\|\.f95$\|\.f03$\|\.f$\|\.for$':
			\['!', '!', '/']
			\}

function! s:filetype()
	let l:f = s:filename()

	let s:start	= '#'
	let s:end	= '#'
	let s:fill	= '*'

	for type in keys(s:types)
		if l:f =~ type
			let s:start	= s:types[type][0]
			let s:end	= s:types[type][1]
			let s:fill	= s:types[type][2]
		endif
	endfor

endfunction

function! s:ascii(n)
	return s:asciiart[a:n - 3]
endfunction

function! s:textline(left, right)
	let l:left = strpart(a:left, 0, s:length - s:margin * 2 - strlen(a:right))

	return s:start . repeat(' ', s:margin - strlen(s:start)) . l:left . repeat(' ', s:length - s:margin * 2 - strlen(l:left) - strlen(a:right)) . a:right . repeat(' ', s:margin - strlen(s:end)) . s:end
endfunction

function! s:line(n)
	if a:n == 1 || a:n == 11 " top and bottom line
		return s:start . ' ' . repeat(s:fill, s:length - strlen(s:start) - strlen(s:end) - 2) . ' ' . s:end
	elseif a:n == 2 || a:n == 10 " blank line
		return s:textline('', '')
	elseif a:n == 3 || a:n == 5 || a:n == 7 " empty with ascii
		return s:textline('', s:ascii(a:n))
	elseif a:n == 4 " filename
		return s:textline(s:filename(), s:ascii(a:n))
	elseif a:n == 6 " author
		return s:textline("By: " . s:user() . " <" . s:mail() . ">", s:ascii(a:n))
	elseif a:n == 8 " created
		return s:textline("Created: " . s:date() . " by " . s:user(), s:ascii(a:n))
	elseif a:n == 9 " updated
		return s:textline("Updated: " . s:date() . " by " . s:user(), s:ascii(a:n))
	endif
endfunction

function! s:user()
	if exists('g:user42')
		return g:user42
	endif
	let l:user = $USER
	if strlen(l:user) == 0
		let l:user = "marvin"
	endif
	return l:user
endfunction

function! s:mail()
	if exists('g:mail42')
		return g:mail42
	endif
	let l:mail = $MAIL
	if strlen(l:mail) == 0
		let l:mail = "marvin@stduent.42.fr"
	endif
	return l:mail
endfunction

function! s:filename()
	let l:filename = expand("%:t")
	if strlen(l:filename) == 0
		let l:filename = "< new >"
	endif
	return l:filename
endfunction

function! s:date()
	return strftime("%Y/%m/%d %H:%M:%S")
endfunction

function! s:insert()
	let l:line = 11

	" empty line after header
	call append(0, "")

	" loop over lines
	while l:line > 0
		call append(0, s:line(l:line))
		let l:line = l:line - 1
	endwhile
endfunction

function! s:insert_guard()
	" Construit le nom du guard : FILENAME_H (ex: libft.h -> LIBFT_H)
	let l:filename = toupper(substitute(expand('%:t'), '[^a-zA-Z0-9]', '_', 'g'))
	let l:guard    = l:filename

	" Insère les guards après l'en-tête (ligne 12)
	call append(11, '')
	call append(12, '#ifndef ' . l:guard)
	call append(13, '# define ' . l:guard)
	call append(14, '')
	call append(15, '#endif /* ' . l:guard . ' */')

	" Place le curseur entre define et endif
	call cursor(15, 0)
endfunction

function! s:update()
	call s:filetype()
	if getline(9) =~ s:start . repeat(' ', s:margin - strlen(s:start)) . "Updated: "
		if &mod
			call setline(9, s:line(9))
		endif
		call setline(4, s:line(4))
		call setline(6, s:line(6))
		if expand('%:e') == 'h' || expand('%:e') == 'hpp'
			call s:update_guard()
		endif
		return 0
	endif
	return 1
endfunction

function! s:update_guard()
  let l:new_guard = toupper(substitute(expand('%:t'), '[^a-zA-Z0-9]', '_', 'g'))

  let l:total = line('$')
  let l:i     = 1
  while l:i <= l:total
    let l:line = getline(l:i)
    " Ne remplace que les lignes dont la valeur du guard correspond
    " à un nom de fichier .h/.hpp (pattern strict)
    if l:line =~ '^#ifndef \u[A-Z0-9_]*H$'
      let l:old_guard = matchstr(l:line, '^#ifndef \zs.*')
      call setline(l:i, '#ifndef ' . l:new_guard)
    elseif exists('l:old_guard') && l:line == '# define ' . l:old_guard
      call setline(l:i, '# define ' . l:new_guard)
    elseif exists('l:old_guard') && l:line == '#endif /* ' . l:old_guard . ' */'
      call setline(l:i, '#endif /* ' . l:new_guard . ' */')
    endif
    let l:i += 1
  endwhile
endfunction

function! s:stdheader()
	if s:update()
		call s:insert()
		if expand('%:e') == 'h' || expand('%:e') == 'hpp'
      		call s:insert_guard()
    	endif
	endif
endfunction

" Bind command and shortcut
command! Stdheader call s:stdheader ()
map <F1> :Stdheader<CR>
autocmd BufWritePre * call s:update ()
