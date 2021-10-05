/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:21:41 by tlemma            #+#    #+#             */
/*   Updated: 2021/10/05 22:48:02 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./get_next_line.h"


void	ft_free(void *to_free);

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	len;
	size_t	len_s1;
	size_t	len_s2;
	char	*ret;

	if (s2 == NULL)
		return (s1);
	i = 0;
	ret = NULL;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len = len_s1 + len_s2;
	ret = malloc(sizeof(char) * (int)len + 1);
	if (!ret)
		return (NULL);
	while (i < len_s1)
	{
		ret[i] = s1[i];
		i++;
	}
	i = 0;
	while ((i + len_s1) < len && len_s2)
	{
		ret[i + (int)len_s1] = s2[i];
		i++;
	}
	ret[len] = '\0';
	ft_free(&s1);
	ft_free(&s2);
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		j;
	char	*subs;
	size_t	src_len;

	j = 0;
	src_len = ft_strlen(s);
	subs = malloc(sizeof(char) * (len + 1));
	if (subs != NULL)
	{
		while ((j < (int)len) && (start < src_len))
		{
			subs[j] = s[start];
			start++;
			j++;
		}
		subs[j] = '\0';
	}
	return (subs);
}
