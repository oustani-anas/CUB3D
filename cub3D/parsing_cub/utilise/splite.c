/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:27:09 by oalaoui-          #+#    #+#             */
/*   Updated: 2023/04/03 15:10:31 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

static char	*ft_substr(const char *s, int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (0);
	if (start >= ft_strlen((char *)s))
		return (ft_strdup2(""));
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	ft_count_word(char const *s, char c)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0' && s[i] != c)
		{
			nb++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (nb);
}

static size_t	ft_get_len_word(const char *s, int index, char c)
{
	size_t	len_word;

	len_word = 0;
	while (s[index] != '\0' && s[index] != c)
	{
		len_word++;
		index++;
	}
	return (len_word);
}

static char	**free_tab(char **tab, int j)
{
	while (j-- >= 0)
		free(tab[j]);
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		nb_word;
	int		i;
	int		j;

	nb_word = ft_count_word(s, c);
	res = (char **)malloc((nb_word + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (s[i] != '\0' && j < nb_word)
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			res[j] = ft_substr(s, i, ft_get_len_word(s, i, c));
			if (!res[j])
				return (free_tab(res, j));
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	res[j] = 0;
	return (res);
}
