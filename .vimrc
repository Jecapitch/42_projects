syntax on
set tabstop=4
set shiftwidth=4
set smartindent
set noexpandtab
set number
set relativenumber
set cursorline
set cursorcolumn
set ruler
set mouse=a
let g:user42 = 'jepiscic'
let g:mail42 = 'jepiscic@student.42belgium.be'

augroup auto_header
  autocmd!
  " Nouveaux fichiers
  autocmd BufNewFile *.c,*.h,Makefile,*.cpp,*.hpp call s:auto_insert_header()
  " Fichiers existants à l'ouverture
  autocmd BufReadPost *.c,*.h,Makefile,*.cpp,*.hpp call s:auto_insert_header()
augroup END

function! s:auto_insert_header()
  " Vérifie si l'en-tête 42 est déjà présent (ligne 1)
  if getline(1) !~ '^\*\{76\}'
    Stdheader
  endif
endfunction
