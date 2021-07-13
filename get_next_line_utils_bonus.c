/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 23:19:55 by esylva            #+#    #+#             */
/*   Updated: 2021/07/13 23:20:01 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (*(s + i))
			i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!(s2))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*dst;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	len1 = (int)ft_strlen(s1);
	len2 = (int)ft_strlen(s2);
	dst = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = -1;
	while (s1[++i])
		dst[i] = s1[i];
	free(s1);
	s1 = NULL;
	i = -1;
	while (s2[++i])
		dst[len1 + i] = s2[i];
	dst[len1 + i] = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, char c)
{
	char	*t;

	t = (char *)s;
	if (!c || !t)
		return (NULL);
	while (*t)
	{
		if (*t == c)
			return (t);
		t++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*str;
	int		i;

	if (!s || start + len > (int)ft_strlen(s))
		return (NULL);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
