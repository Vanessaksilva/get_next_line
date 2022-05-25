/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:29:39 by coder             #+#    #+#             */
/*   Updated: 2022/05/26 00:52:10 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	int		len;
	int		i;

	len = (int) ft_strlen(s);
	new = malloc(sizeof (char) * len + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*ft_substr(char const *str, unsigned int start,
size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	slen;
	unsigned int	tlen;

	i = 0;
	slen = ft_strlen(str);
	if (start >= slen)
		tlen = 1;
	else if (len >= slen)
		tlen = slen - start + 1;
	else
		tlen = len + 1;
	sub = (char *)malloc(tlen);
	if (sub == NULL)
		return (NULL);
	while ((start < slen) && (i < len))
	{
		sub[i] = str[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("\0");
	while (s1[i])
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	free(s1);
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*first;

	i = 0;
	first = NULL;
	if (!s)
		return (NULL);
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			first = (char *)&s[i];
			break ;
		}
		i++;
	}
	return (first);
}
