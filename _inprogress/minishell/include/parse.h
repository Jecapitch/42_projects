/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:17:57 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/11 19:26:21 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/* FLAGS */

# define FTEXT		0x000
# define FQUOTE		0x010
# define FDQUOTE	0x020
# define FBQUOTE	0x040
# define FCOLON		0x100
# define FESC		0x001
# define FDOLLAR	0x002
# define FVARNAME	0x003
# define FEQUAL		0x004
# define FVARVAL	0x005
# define FWILDCARD	0x006

#endif
