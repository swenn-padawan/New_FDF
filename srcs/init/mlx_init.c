#include "fdf.h"
#include "mlx.h"

void	fdf_mlx_init(t_mlx *mlx){
	mlx->mlx = mlx_init();
	mlx->info.title = TITLE;
	mlx->info.height = WINDOW_HEIGHT;
	mlx->info.width = WINDOW_WIDTH;
	mlx->win = mlx_new_window(mlx->mlx, &mlx->info);
}
