/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:30:31 by emanukya          #+#    #+#             */
/*   Updated: 2024/02/27 17:30:33 by emanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*str)
	{
		str++;
		length++;
	}
	return (length);
}

void	ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p_b;

	p_b = b;
	while (len > 0)
	{
		*p_b = c;
		p_b++;
		len--;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if ((count > 65535 || size > 65535)
		&& (count > 0 && 65535 / count < size))
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, count * size);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (s1 == NULL)
		return (s2);
	newstring = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstring == NULL)
		return (NULL);
	while (s1[i])
	{
		newstring[i] = s1[i];
		i++;
	}
	while (s2[n])
	{
		newstring[i + n] = s2[n];
		n++;
	}
	newstring[i + n] = '\0';
	free(s1);
	free(s2);
	return (newstring);
}
