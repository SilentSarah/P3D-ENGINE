/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:43:53 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/16 15:09:03 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"
#include "../INCLUDES/raycast.h"

int	main(int ac, char **av)
{
	t_map	*mlx;

	if (ac == 2)
	{
		initialize_mlx(&mlx);
		if (load_map(av[1], mlx->data))
		{
			ft_malloc(-1);
			exit (1);
		}
		if (extract_map_data(mlx->data) || draw_2d_map(mlx))
		{
			ft_printf(2, "%s", INV_ERR);
			free_2d_array(mlx->data->cnf);
			free_2d_array(mlx->data->map);
			ft_malloc(-1);
			exit (1);
		}
		ft_printf(1, "TEST\n");
		hook_functions(mlx);
	}
	return (0);
}
