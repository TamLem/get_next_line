/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:40:09 by tlemma            #+#    #+#             */
/*   Updated: 2021/10/09 19:12:07 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

#include <sys/stat.h>
#include <fcntl.h>


void buf_scroll(char *buf, size_t i)
{
	size_t n = 0;

	while (buf[n] != '\0')
	{
		// printf("%zu\n", n);
		if (buf[n+i] == '\0')
		{
			while (buf[n] != '\0')
				buf[n++] = '\0';
			break ;
		}
		buf[n] = buf[n+i];
		n++;
	}
	
}

void	ft_free(char **to_free)
{
	if(*to_free != NULL)
	{
		free(*to_free);
		*to_free = NULL;
	}
}

char	*get_next_line(int fd)
{
	char 			*line;
	size_t			i = 0;
	ssize_t			n = 0;
	static char 	*buf = NULL;

	// printf("\nc: %d\n", counter++);
	line = NULL;
	if (buf == NULL)
	{
		buf = malloc(BUFFER_SIZE + 1);
		buf[0] = '\0';
	}
	if (*buf == '\0')
	{
		n = read(fd, buf, BUFFER_SIZE);
		buf[n] = '\0';
		if (n <= 0 && buf != NULL)
		{
			ft_free(&buf);
			// printf("free 82: %s\n", buf);
			return (NULL);
		}
	}
	while(buf[i] != '\n' && buf[i+1] != '\0')
		i++;
	line = ft_substr(buf, 0, i+1);
	buf_scroll(buf, i + 1);
	// printf("line : %s\n", line);
	if (line[i] == '\n')
		return (line);
	if (n < BUFFER_SIZE && n != 0) //last read in case buf.size > 1
	{
		// ft_free(&buf);
		return (line);
	}
	line = ft_strjoin(line, get_next_line(fd));
	// if (n <= BUFFER_SIZE || buf != NULL)
	// {
	// 	ft_free(&buf);
	// 	// printf("free 103 %s\n", buf);
	// }

	return (line);
}

// int	main(void)
// {
// 	// 	int	c = 0;
// 	// 	// char s[6] = "Hallo";
// 		int fd;

// 	fd = open("./tester/files/multiple_line_no_nl", O_RDONLY);

// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
		
// 	// 	// buf_scroll(s, 2);
// 	// 	// printf("%s", s);
	
	
// 	return (0);
// }
