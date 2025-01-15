# include "../libs/minilibx/mlx.h"
#include <stdio.h>

int handle_keypress(int keycode, void *param)
{
    (void)param; // Evitar advertencias si no usas el parámetro
    printf("Key pressed: %d\n", keycode);
    return (0);
}

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    if (!mlx)
    {
        printf("Error initializing mlx\n");
        return (1);
    }

    win = mlx_new_window(mlx, 800, 600, "Test Keyboard");
    if (!win)
    {
        printf("Error creating window\n");
        return (1);
    }

    mlx_hook(win, 2, 1L << 0, handle_keypress, NULL); // Captura el evento de tecla presionada
    mlx_loop(mlx);

    return (0);
}
