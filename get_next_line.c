/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:07:44 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/04/10 12:21:48 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	buffer[100];
	int		chars_read;

	fd = open("test.txt", O_RDWR | O_CREAT);
	while ((chars_read = read(fd, buffer, 30)) > 0)
	{
		write(1, buffer, chars_read);
		write(1, "\n", 1);
	}
}
