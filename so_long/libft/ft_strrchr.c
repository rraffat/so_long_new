/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffat <rraffat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:39:06 by rraffat           #+#    #+#             */
/*   Updated: 2021/12/25 16:49:53 by rraffat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

// int	main(void)
// {
// 	char	s[20] = "Hi Every One";
// 	char	c = 'v';
// 	char *a;

// 	a = ft_strrchr(s, c);
// 	printf("my function :  %s\n" , a);
// }
