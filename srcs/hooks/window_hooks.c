#include "fdf.h"
#include "mlx.h"

void	key_hook(int key, void *params){
	t_mlx	*clone;

	clone = (t_mlx *)params;
	if (key == 41)
		mlx_loop_end(clone->mlx);
}
