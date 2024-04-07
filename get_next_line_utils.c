/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:00:32 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/04/07 14:08:00 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
