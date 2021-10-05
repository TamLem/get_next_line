/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:40:09 by tlemma            #+#    #+#             */
/*   Updated: 2021/10/05 16:48:29 by tlemma           ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char 			*line;
	size_t			i = 0;
	static size_t	n = 0;
	static char 	*buf = NULL;
	// static int		counter = 0;
	
	// if(counter++ == 5)
	// 	return NULL;

	if (buf == NULL)
	{
		buf = malloc(BUFFER_SIZE + 1);
		buf[BUFFER_SIZE + 1] = '\0';
	}
	if (*buf == '\0')
		n = get_buf(buf, fd);
	
	// tf("\nread %s\n", buf);
	// return (buf);
	while(buf[i] != '\n' && buf[i])
		i++;
	if (!buf[i])
		i--;
	if (buf[i] == '\n')
	{
		buf_scroll(buf, i + 1);
		return (line);
	}
	
	line = ft_substr(buf, 0, i+1);
	// i++;
	// printf("line: %s\n", line);
	buf_scroll(buf, i + 1);
	printf("i: %zu\t line[i]: %c\n", i, line[i-1]);
	if (line[i] == '\n')
		return (line);
	if (line[i] != '\n' && line[i] == '\0') //when \n is not in the buffer
	{
		// printf("\n couter: %d\n", counter);
		// return NULL;
		line = ft_strjoin(line, get_next_line(fd));
	}
	
	if (n < BUFFER_SIZE && !buf)
	{
		free(buf);
		buf = NULL;
	}

	return (line);
}


int	main(void)
{
	int	c = 0;
	// char s[6] = "Hallo";

	printf("\nr: %s", get_next_line(0));
	// printf("r: %s", get_next_line(0));
	// printf("r: %s", get_next_line(0));
	// printf("r: %s", get_next_line(0));
	// printf("r: %s", get_next_line(0));
	
	// buf_scroll(s, 2);
	// printf("%s", s);
	
	return (0);
}
