/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:23:03 by bfaras            #+#    #+#             */
/*   Updated: 2025/03/21 21:34:22 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	int				i;

	uc = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == uc)
			return ((char *)&s[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

static char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static void	*ft_free(char **buffer, char *tmp)
{
	free(*buffer);
	*buffer = tmp;
	return (NULL);
}

static char	*get_new_line(char **stash)
{
	char	*line;
	size_t	newline_index;
	char	*tmp;

	line = NULL;
	tmp = NULL;
	if (*stash && **stash)
	{
		if (ft_strchr(*stash, '\n'))
		{
			newline_index = ft_strchr(*stash, '\n') - *stash;
			line = ft_substr(*stash, 0, newline_index + 1);
			if (!line)
				return (NULL);
			tmp = ft_strdup(*stash + newline_index + 1);
			if (!tmp)
				return (ft_free(&line, NULL));
		}
		else
			line = ft_strdup(*stash);
	}
	ft_free(stash, tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*tmp;
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (ft_free(&buffer, NULL), ft_free(&stash, NULL));
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buffer);
		ft_free(&stash, tmp);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	ft_free(&buffer, NULL);
	return (get_new_line(&stash));
}
