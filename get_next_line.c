/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:07:44 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/04/11 12:59:57 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_line(char *line);
static char	*complete_line(int fd, char *temp, char *buffer);
static char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(temp);
		free(buffer);
		temp = NULL;
		buffer = NULL;
		return (0);
	}
	if (!buffer)
		return (NULL);
	line = complete_line(fd, temp, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	temp = set_line(line);
	return (line);
}

static char	*set_line(char *line)
{
	char	*temp;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0)
		return (0);
	temp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*temp == 0)
	{
		free(temp);
		temp = NULL;
	}
	line[i + 1] = 0;
	return (temp);
}

static char	*complete_line(int fd, char *temp, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(temp);
			return (0);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!temp)
			temp = ft_strdup("");
		tmp = temp;
		temp = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (temp);
}

static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		num_line;

// 	num_line = 1;
// 	fd = open("test.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%d: %s\n", num_line++, line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
