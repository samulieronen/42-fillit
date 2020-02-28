/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:52:22 by seronen           #+#    #+#             */
/*   Updated: 2019/12/19 15:49:48 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_error(int err)
{
	if (err == 0)
		ft_putstr_fd("error\n", 2);
	else
		ft_putstr_fd("usage: ./fillit source_file\n", 2);
	exit(1);
}

void		ft_check_bc(t_list *h)
{
	int counter;

	counter = 0;
	while (h)
	{
		counter++;
		h = h->next;
	}
	if (counter > 26)
		ft_error(0);
}

t_coord		*ft_lstnew_coord(void)
{
	t_coord		*new;

	if (!(new = (t_coord*)malloc(sizeof(t_coord))))
		ft_error(0);
	new->next = NULL;
	return (new);
}

void		ft_delete_list(t_list *current)
{
	t_list	*next;

	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	free(current);
}

void		ft_delete_coord(t_coord *c)
{
	t_coord *n;

	while (c != NULL)
	{
		n = c->next;
		free(c);
		c = n;
	}
	free(c);
}
