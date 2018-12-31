/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 00:57:28 by yijhuang          #+#    #+#             */
/*   Updated: 2018/12/31 15:54:30 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		num;
	int		len;
	char	**str;

	i = 0;
	j = 0;
	num = ft_words_count(s, c);
	str = (char**)malloc((num + 1) * sizeof(char*));
	if (!str)
		return (NULL);
	else if (num == 0)
	{
		str[0] = 0;
		return (str);
	}
	else
	{
		while (num--)
		{
			while (*(s + i) == c && *(s + i) != '\0')
				i++;
			len = ft_word_len((s + i), c);
			str[j] = ft_strsub((s + i), 0, len);
			if (!str[j])
				return (NULL);
			else
			{
				i = i + len;
				j++;
			}
		}
		str[j] = NULL;
		return (str);
	}
}
