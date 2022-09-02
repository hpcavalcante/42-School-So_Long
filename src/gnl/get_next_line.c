/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:52:41 by hepiment          #+#    #+#             */
/*   Updated: 2022/08/15 17:58:03 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*ft_get_str(int fd, char *read_line)
{
	int		r_bytes;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	r_bytes = 1;
	while (!ft_strchr(read_line, '\n') && r_bytes != 0)
	{
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		if (r_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[r_bytes] = '\0';
		read_line = ft_strjoin(read_line, buffer);
	}
	free(buffer);
	return (read_line);
}

char	*get_next_line(int fd)
{
	static char	*get_str;
	char		*next_line;

	next_line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	get_str = ft_get_str(fd, get_str);
	if (!get_str)
		return (NULL);
	next_line = ft_return(get_str);
	get_str = ft_last_position(get_str);
	if (next_line[0] == '\0')
	{
		free(get_str);
		free(next_line);
		return (NULL);
	}
	return (next_line);
}
