/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:39:39 by sbars             #+#    #+#             */
/*   Updated: 2022/08/18 17:19:02 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
// remove after testing!!
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char	**argv)
{
	t_data	*pkg;

	pkg = NULL;
	if (argc < 5)
		errormsg("enter more arguments", pkg);
	else if (argc > 6)
		errormsg("too many args", pkg);
	pkg = init_pkg(pkg);
	fill_pkg(pkg, argv);
	if (argc == 6)
		pkg->eatXtimes = ft_atoi(argv[argc - 1]);
	printf("%d\n", pkg->pc);
	printf("%d\n", pkg->t2die);
	printf("%d\n", pkg->t2eat);
	printf("%d\n", pkg->t2sleep);
	printf("%d\n", pkg->eatXtimes);
	return (0);
}
