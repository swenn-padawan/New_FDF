/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:24:10 by stetrel           #+#    #+#             */
/*   Updated: 2025/04/26 23:55:24 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "mlx.h"
#include "libft.h"
# include "mlx_extended.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <ctype.h>

# define TITLE "FDF"
# define WINDOW_WIDTH  400
# define WINDOW_HEIGHT 400

# define UNUSED __attribute__((unused))
# define BUFFER_SIZE 65536

typedef enum e_parsing{
	SUCCESS	= 0,
	BAD_FILE,
	FSTAT_FAILED,
	READ_FAILED
}t_parsing;

typedef struct	s_mlx{
	mlx_context				mlx;
	mlx_window_create_info	info;
	mlx_window				win;
}	t_mlx;

typedef union	s_colors{
    struct
    {
        #if MLX_BYTEORDER == MLX_LITTLE_ENDIAN
            uint8_t a;
            uint8_t b;
            uint8_t g;
            uint8_t r;
        #else
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
        #endif
    };
    uint32_t rgba;	
}	t_colors;

typedef struct	s_data{
	size_t		nb_cols;
	size_t		nb_rows;
	int			*data;
	t_colors	*colors;
	int			parse_index;
}	t_data;

//init
void	fdf_mlx_init(t_mlx *mlx);

//hooks
void	key_hook(int key, void *params);

//parsing
char	*get_file(char *map);
t_data	*fdf_fill_data(char *buffer);

