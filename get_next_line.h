/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:13:06 by tlemma            #+#    #+#             */
/*   Updated: 2021/10/05 15:37:40 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

# endif