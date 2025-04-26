#include "fdf.h"
#include "mlx.h"

void	fdf_mlx_init(t_mlx *mlx){
	mlx->mlx = mlx_init();
	mlx->info.title = TITLE;
	mlx->info.height = HEIGHT;
	mlx->info.width = WIDTH;
	mlx->win = mlx_new_window(mlx->mlx, &mlx->info);
}
