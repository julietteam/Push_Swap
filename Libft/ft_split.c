/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:47:43 by juandrie          #+#    #+#             */
/*   Updated: 2023/05/17 12:18:29 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
				i++;
	}
	return (word);
}

static char	*size(char const *s, char c)
{
	char	*s2;
	int		i;
	int		longueur;

	i = 0;
	longueur = 0;
	while (s[longueur] != c && s[longueur] != '\0')
		longueur++;
	s2 = ft_calloc(longueur + 1, sizeof (char));
	if (!s2)
		return (NULL);
	while (i < longueur)
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}

static char	**ft_free(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free (tab);
		i++;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = ft_calloc((count_word(s, c)) + 1, sizeof (char *));
	if (!tab)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			tab[j] = size(&s[i], c);
			if (!tab[j])
				return (ft_free(tab));
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (tab);
}
/*
int	main(void)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split("Hello***World***!!*ca marche*", '*');
	while (i < 5)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
*/