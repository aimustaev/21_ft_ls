/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:22:06 by slynell           #+#    #+#             */
/*   Updated: 2020/08/17 00:13:21 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <sys/ioctl.h>
# include "../libft/header/libft.h"


# define L_OPT 		1
# define RR_OPT 	2
# define A_OPT 		4
# define R_OPT 		8
# define T_OPT 		16

enum				{ERROR, USAGE};

typedef struct		s_ls {
	int				opt;
	int				index;
}					t_ls;

typedef struct		s_lst_file {
	struct s_lst_file	*parent;
	struct s_lst_file	*child;
	struct s_lst_file	*prev;
	struct s_lst_file	*next;
	char			*path;
	char			*name;
	struct stat		stat;
}					t_lst_file;
/*
** ========================== ERROR FUNCTION ===================================
*/

void				ls_lstat_error(t_lst_file *lst);
int 				ls_error(char *s, int error);

/*
** ===================== SUPPORT FUNCTION LIST FILES ===========================
*/
t_lst_file			*ls_lst_create(void);
t_lst_file			*ls_lst_add(t_lst_file *lst);
t_lst_file			*ls_lst_get_start(t_lst_file *lst);
t_lst_file			*ls_lst_reverse(t_lst_file *lst);
void				ls_lst_free(t_lst_file *lst);

#endif