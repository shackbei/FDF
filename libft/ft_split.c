/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:09:33 by shackbei          #+#    #+#             */
/*   Updated: 2021/09/04 17:09:33 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(char ***b, int word)
{
	while (--word >= 0)
		free((*b)[word]);
	free (*b);
	return (NULL);
}

int	ft_condition(char const *s, char c, int *i)
{
	return ((s[(*i)++] == c && s[*i] != c && s[*i] && s[*i] != '\n')
		 || (*i - 1 == 0 && s[(*i) - 1] != c));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		end;
	int		word;
	char	**b;

	i = 0;
	word = 0;
	if (s == '\0')
		return (NULL);
	while (s[i] != '\0')
		if (ft_condition(s, c, &i))
			word++;
	b = ft_calloc(word + 1, sizeof(char *));
	while (word-- > 0 && b != NULL)
	{
		while (i > 0 && (s[i] == c || s[i] == '\0' || s[i] == '\n'))
			i--;
		end = i;
		while (i >= 0 && s[i] != c)
			i--;
		b[word] = ft_substr(s, i + 1, end - i);
		if (b[word] == NULL)
			return (ft_free(&b, word));
	}
	return (b);
}
