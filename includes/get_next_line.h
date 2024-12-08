/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:34:31 by mratke            #+#    #+#             */
/*   Updated: 2024/11/04 15:43:28 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// includes
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
// Utils
int		is_in_str(char *s, char c);
char	*ft_strdup(const char *src);
char	*ft_str_merge(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*line_validator(char *s);
char	*read_and_merge(int fd, char *current_line);

#endif
