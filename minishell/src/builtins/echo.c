/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:55:04 by dowon             #+#    #+#             */
/*   Updated: 2023/07/04 15:55:41 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <stdio.h>
#include <libft.h>

t_exit_code	echo(int argc, char *argv[])
{
	int	idx;

	if (argc == 1)
	{
		printf("\n");
		return (0);
	}
	idx = 0;
	if (ft_strncmp(argv[1], "-n", 2))
		idx = 1;
	while (idx + 1 < argc)
		printf("%s ", argv[idx]);
	printf("%s", argv[idx]);
	if (!ft_strncmp(argv[1], "-n", 2))
		printf("\n");
	return (0);
}
