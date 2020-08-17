/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_get_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/08/17 19:35:03 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_ls.h"

int			ls_lst_get_length(t_lst_file *lst)
{
	t_lst_file	*temp_lst;
	int			c;

	c = 1;
	temp_lst = lst;
	while (temp_lst->next)
	{
		c++;
		temp_lst = temp_lst->next;
	}
	return (c);
}