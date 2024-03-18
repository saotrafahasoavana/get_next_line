/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saotra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:35:04 by saotra            #+#    #+#             */
/*   Updated: 2023/12/18 00:51:06 by saotra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (*(char *)s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	s = (char *)malloc((ft_strlen(s2) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j])
			s[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j])
			s[i++] = s2[j++];
	s[i] = '\0';
	//free(s1);
	return (s);
}

char	*ft_strdup(char	*s)
{
	char	*d;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	d = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);	
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int		i;
	char	*substr;
	int		len_sub;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	len_sub = ft_strlen(s) - start;
	if (len < len_sub)
		len_sub = len;
	substr = (char *)malloc(sizeof(char) * (len_sub + 1));
	if (substr == NULL)
		return (NULL);
	while (i < len_sub)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
