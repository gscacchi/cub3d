#include "../cub3d.h"

int        main(int argc, char **argv)
{
    //void    *mlx_ptr;
    //void      vars.win;
    t_parse parse;
    t_vars vars;
    vars.time = 0;
    vars.oldTime = 0;
    vars.gscala = 0;

    map_parsing(argv[1], &parse);
    ft_init_vars(&vars, &parse);
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, vars.ScreenWidth, vars.ScreenHeight, "Cub3V");
    vars.mlx = vars.mlx;
    vars.win =  vars.win;
    vars.moveSpeed = 0.11;
    vars.rotSpeed = 0.07;
    mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
    mlx_hook(vars.win, 3, 1L<<1, ft_release, &vars);
    mlx_hook(vars.win, 17, 1L<<5, ft_exit, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);

    mlx_loop(vars.mlx);
}