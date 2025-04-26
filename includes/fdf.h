/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:24:10 by stetrel           #+#    #+#             */
/*   Updated: 2025/04/26 19:51:49 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "mlx.h"
#include "mlx_extended.h"
#include <stdio.h>

#define TITLE "FDF"
#define WIDTH  400
#define HEIGHT 400

typedef struct	s_mlx{
	mlx_context				mlx;
	mlx_window_create_info	info;
	mlx_window				win;
}	t_mlx;

//init
void	fdf_mlx_init(t_mlx *mlx);

//hooks
void	key_hook(int key, void *params);

