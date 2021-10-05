/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:40:09 by tlemma            #+#    #+#             */
/*   Updated: 2021/10/05 23:41:17 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

// #define BUFFER_SIZE 10

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	get_buf(char *buf, int fd)
{
	size_t	n;

	n = 0;
	n = read(fd, buf, BUFFER_SIZE);
	return (n);
}

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
	if(to_free != NULL)
	{
		free(*to_free);
	}
	*to_free = NULL;
}

char	*get_next_line(int fd)
{
	char 			*line;
	size_t			i = 0;
	size_t			n = 0;
	static char 	*buf = NULL;
	// static int		counter = 0;
	
	// if(counter++ == 5)
	// 	return NULL;

	// printf("\nc: %d\n", counter++);
	line = NULL;
	if (buf == NULL)
	{
		// printf("malloc buf\n");
		buf = malloc(BUFFER_SIZE + 1);
		buf[BUFFER_SIZE] = '\0';
	}
	if (*buf == '\0')
	{
		n = get_buf(buf, fd);
		// printf("n: %zu\n", n);
		if (n <= 0 && buf != NULL)
		{
			// printf("free 82\n");
			ft_free(&buf);
			return (NULL);
		}
	}
	while(buf[i] != '\n' && buf[i+1])
		i++;
	// printf("\ni: %zu\n", i);
	line = ft_substr(buf, 0, i+1);
	buf_scroll(buf, i + 1);
	if (line[i] == '\n')
		return (line);
	if (n < BUFFER_SIZE && n != 0)
		return (line);
	line = ft_strjoin(line, get_next_line(fd));
	// printf("line: %s\n", line);
	
	// printf("\nread %d", buf == NULL ? 1 : 0);
	if (n <= BUFFER_SIZE && buf != NULL)
	{
		// printf("free 103\n");
		ft_free(&buf);
	}

	// system("leaks main | grep \"leaked bytes\"");
	return (line);
}


// int	main(void)
// {
// 	int	c = 0;
// 	// char s[6] = "Hallo";

// 	printf("r: %s", get_next_line(0));
// 	printf("r: %s", get_next_line(0));
// 	// printf("r: %s", get_next_line(0));
// 	// printf("r: %s", get_next_line(0));
// 	// printf("r: %s", get_next_line(0));
	
// 	// buf_scroll(s, 2);
// 	// printf("%s", s);
	
	
// 	return (0);
// }
