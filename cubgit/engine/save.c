#include "../cub3d.h"

static void	color_to_char(int color, int fd)
{
	unsigned char rgb[4];
	rgb[0] = (unsigned char)color;
	rgb[1] = (unsigned char)(color >> 8);
	rgb[2] = (unsigned char)(color >> 16);
	rgb[3] = (unsigned char)(color >> 24);
	write(fd, rgb, 4);
}
void    bmp_print(t_vars *win, t_data *image, int fd)
{
    int *addr;
    int             x;
    int             y;
    int             dst;
    int     resx = (int)win->ScreenWidth;
    int     resy = (int)win->ScreenHeight;
    y = resy - 1;
    dst = 0;
    addr = (int *)image->addr;
    while (y >= 0)
    {
        x = 0;
        while (x < resx)
        {
            //dst = (*(int *)(image->addr + (y * image->line_length + (x * 4))));
            dst = addr[(y * resx) + x];
            color_to_char(dst, fd);
            //write(fd, &dst, 4);
            x++;
        }
        y--;
    }
}
void    bmp_header_2(t_vars *win, t_data *image, int fd)
{
    int             plane;
    int             color;
    int             imgsize;
    int             resx;
    int             resy;
    resx        =   (int)win->ScreenWidth;
    resy        =   (int)win->ScreenHeight;
    plane       =   1;
    color       =   0;
    imgsize     =   resx * (resy - 1) * 4;
    write(fd, &plane, 2);
    write(fd, &image->bits_per_pixel, 2);
    write(fd, "\0\0\0\0", 4);
    write(fd, &imgsize, 4);
    write(fd, &color, 4);
    write(fd, &color, 4);
    write(fd, &color, 4);
    write(fd, &color, 4);
}
void    bmp_header(t_vars *win, int fd)
{
    int             filesize;
    int             offset;
    int             infoheader;
    int             resx;
    int             resy;
    resx        =   (int)win->ScreenWidth;
    resy        =   (int)win->ScreenHeight;
    filesize    =   resx * resy * 4 + 54;
    offset      =   54;
    infoheader  =   40;
    write(fd, "BM", 2);
    write(fd, &filesize, 4);
    write(fd, "\0\0\0\0", 4);
    write(fd, &offset, 4);
    write(fd, &infoheader, 4);
    write(fd, &resx, 4);
    write(fd, &resy, 4);
}
int     ft_bitmap(t_vars *win, t_data *image)
{
    int fd;
    fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_APPEND | O_TRUNC | S_IRWXU, 00755);
    bmp_header(win, fd);
    bmp_header_2(win, image, fd);
    bmp_print(win, image, fd);
    close (fd);
    return (1);
}