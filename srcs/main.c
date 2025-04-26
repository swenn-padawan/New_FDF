#include "fdf.h"

int main()
{
	t_mlx	mlx;

	fdf_mlx_init(&mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_loop(mlx.mlx);
}
