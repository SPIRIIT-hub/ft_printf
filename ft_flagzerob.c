/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagzerob.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:11:42 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/04 17:15:19 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_star(const char *str)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (!(str[i] != '%' || (str[i] == '%' && str[i + 1] == '%')))
			if (is_in('*', ft_returnflag(str + i)))
				ret++;
		i++;
	}
	return (ret);
}

int		ft_retzero2(const char *str, char **container, size_t **i)
{
	int		a;
	int		tmpa;

	a = ft_getprcta(str);
	tmpa = a > 0 ? a : -a;
	if (container[**i][0] == '-')
		ft_putstr(container[**i] + 1);
	else if (a > 0)
		ft_putstr(container[(**i)]);
	(**i)++;
	free((char *)str);
	str = 0;
	return (tmpa);
}

int		ft_retzero2b2(const char *str, char **container, size_t **i)
{
	int		a;
	int		tmpa;
	size_t	j;

	a = ft_getprcta(str);
	tmpa = a > 0 ? a : -a;
	j = 0;
	if (a < 0)
	{
		if (container[**i][0] == '-')
			ft_putstr(container[**i] + 1);
		else
			ft_putstr(container[**i]);
		ft_putspace(tmpa - ft_strlen(container[(**i)++]));
		return (tmpa);
	}
	while (j < (tmpa - ft_strlen(container[(**i)])))
	{
		if (a < 0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		j++;
	}
	return (ft_retzero2(str, container, &(*i)));
}

int		ft_nbargsttwo3(const char *str, char **container, size_t **i)
{
	long	a;
	long	b;
	long	tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a > 0 ? a : -a;
	if (b == 0 && a == 0 && ft_rettype(str) == 's')
		return (0);
	if (a == 0 && ft_rettype(str) == 'c')
	{
		write(1, container[(**i)++], 1);
		return (1);
	}
	write(1, " ", 1);
	(**i)++;
	return (1);
}

int		ft_nbargsttwo4(const char *str, char **container, size_t **i)
{
	long	b;
	long	tmpa;

	b = ft_getb(str);
	tmpa = ft_geta(str) > 0 ? ft_geta(str) : -ft_geta(str);
	if (container[**i][0] == '-' && is_in(ft_rettype(str), "uid"))
	{
		write(1, "-", 1);
		tmpa = b - ft_strlen(container[**i]) + 1;
		if (tmpa > 0)
			ft_putzerob(tmpa);
		ft_putstr(container[(**i)++] + 1);
		return (b + 1);
	}
	else if (is_in(ft_rettype(str), "uidxX"))
	{
		ft_putzerob(b - ft_strlen(container[**i]));
		ft_putstr(container[(**i)++]);
		return (b);
	}
	if (b > ft_strlen(container[**i]))
		b = ft_strlen(container[**i]);
	ft_putstr_len(container[(**i)++], b);
	return (b);
}
