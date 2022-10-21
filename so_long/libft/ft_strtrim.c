/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffat <rraffat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 06:56:59 by rraffat           #+#    #+#             */
/*   Updated: 2021/12/27 06:57:33 by rraffat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_for_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1)
		return (0);
	while (s1[start] && check_for_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && check_for_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, (end - start)));
}

static int	check_for_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
