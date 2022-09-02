/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:17:22 by hepiment          #+#    #+#             */
/*   Updated: 2022/06/30 09:34:20 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, int found);
char	*ft_strjoin(char *dup_str, char *buffer);
char	*ft_return(char *backup);
char	*ft_last_position(char *next_str);
char	*get_next_line(int fd);
char	*ft_get_str(int fd, char *read_line_str);

#endif
