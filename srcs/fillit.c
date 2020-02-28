/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:12:46 by seronen           #+#    #+#             */
/*   Updated: 2019/12/22 15:16:57 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_buf(const char *s)
{
	int i;
	int ln;
	int dot;

	i = 0;
	ln = 0;
	dot = 0;
	while (s[i])
	{
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			ft_error(0);
		if (s[i] == '\n' && s[i + 1] != '\n')
			ln++;
		if (s[i] == '.')
			dot++;
		i++;
	}
	if (ln > 4 || dot != 12)
		ft_error(0);
	return (0);
}

static t_list	*ft_read_file(int fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	t_list	*head;
	t_list	*new;

	head = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (head == NULL)
		{
			if ((!(new = ft_lstnew(buf, 25))) || ret < 20 || ft_buf(buf))
				ft_error(0);
			ft_validate_block(new->content);
			head = new;
		}
		else if (head != NULL)
		{
			if ((!(new->next = ft_lstnew(buf, 25))) || ret < 20 || ft_buf(buf))
				ft_error(0);
			new = new->next;
			ft_validate_block(new->content);
		}
	}
	return (head);
}

static int		ft_headquarters(int fd)
{
	t_list *head;

	if (!(head = ft_read_file(fd)))
		ft_error(0);
	ft_check_bc(head);
	ft_check_integrity(head);
	ft_prepare(head, 2);
	return (0);
}

int				main(int ac, char **av)
{
	int fd;

	if (ac != 2)
		ft_error(1);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_headquarters(fd);
		close(fd);
	}
	return (0);
}
