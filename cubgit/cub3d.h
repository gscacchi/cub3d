#ifndef CUB3D_H
# define CUB3D_H

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;




typedef struct  s_tex   {
    char    *path;
    void    *img;
    char    *addr;
    int     *colors;
    int     width;
    int     height;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_tex;

typedef	struct	s_parse
{
	int		res_w;
	int		res_h;
	int		n_wall[3];
	int		s_wall[3];
	int		w_wall[3];
	int		e_wall[3];
	int		sky[3];
	int		floor[3];
	int		ceiling[3];
	char	*wall[4];
	char	*sfc[3];
	char	**map;
	char	reference[8];
	int		map_h;
}				t_parse;

typedef struct	s_checker
{
	int		r;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		s;
	int		f;
	int		c;
	int		err;
}				t_checker;
t_checker   g_check;

typedef struct s_keys{
  int  keyUp;
  int  keyDown;
  int  keyLeftView;
  int  keyRightView;
  int  keyLeft;
  int  keyRight;
}             t_keys;

typedef struct  s_sprite    {
    double  x;
    double  y;
}               t_sprite;

typedef struct  s_vars {
    int         gscala;
    void        *towD_win;
    void        *mlx;
    void        *win;
    int         x;
    int         y;
    double      posX;
    double      posY;  //x and y start position
    double      dirX;
    double      dirY; //initial direction vector
    double      planeX;
    double      planeY; //the 2d raycaster version of camera plane
    double      time; //time of current frame
    double      oldTime; //time of previous frame
    double      camX;
    double      camY;
    double      cameraX; //x-coordinate in camera space
    double      rayDirX;
    double      rayDirY;
    double      rayDirX0;
    double      rayDirX1;
    double      rayDirY0;
    double      rayDirY1;
    int         p;
    float       posZ;
    float       rowDistance;
    float       floorStepX;
    float       floorStepY;
    float       floorX;
    float       floorY;
    int         cellX;
    int         cellY;
    int         tx;
    int         ty;
    //which box of the map we're in
    int         mapX;
    int         mapY;

    //length of ray from current position to next x or y-side
    double      sideDistX;
    double      sideDistY;

    //length of ray from one x or y-side to next x or y-side
    double      deltaDistX;
    double      deltaDistY;
    double      perpWallDist;

    //what direction to step in x or y-direction (either +1 or -1)
    int         stepX;
    int         stepY;

    int         hit; //was there a wall hit?
    int         side; //was a NS or a EW wall hit?
    //calculate step and initial sideDist
    int         lineHeight;

      //calculate lowest and highest pixel to fill in current stripe
    int         drawStart;
    int         drawEnd;
    double      frameTime;
    double      moveSpeed; //the constant value is in squares/second
    double      rotSpeed;
    double      oldDirX;
    double      oldPlaneX;
    t_tex       texture[7];
    int         textNum;
    double      wallX;
    int         texX;
    int         texY;
    double      step;
    double      texPos;
    int         color;
    //keys
    int  keyUp;
    int  keyDown;
    int  keyLeftView;
    int  keyRightView;
    int  keyLeft;
    int  keyRight;
    int  ScreenHeight;
    int  ScreenWidth;
    char    **map;
    int     mapHeight;
    int     mapWidth;
    int     nSprites;
    char    dir;
 //sprite
    double      spriteX;
    double      spriteY;
    double      invDet;
    double      transformX;
    double      transformY;
    int         spriteScreenX;
    int         spriteHeight;
    int         drawStartY;
    int         drawEndY;
    int         spriteWidth;
    int         drawStartX;
    int         drawEndX;
    int         stripe;
    int         d;
}               t_vars;

int	    ft_isdigit(int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_realloc(char **line);
char	*ft_realloc_finale(char **line);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char	**ft_split(char *s, char c);
size_t	ft_strclen(char *s, char c);
size_t	ft_strcount(char *str, char c);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		parse_sfc(char **line, t_parse *g_p);
int		parse_wall(char **line, t_parse *g_p);
int		res_parse(char **line, t_parse *g_p);
void	rgb_parse(char **line, int rgb[3]);
int		parsing(char **line, int fd, t_parse *g_p);
int     map_parse(char **line, int fd, t_parse *g_p);
char	*w_tx(char **line);
int     sfc_tx(char **line, t_parse *g_p);
int		parse_tx(char **line, t_parse *g_p);
int		get_next_line(int fd, char **line);
int		ft_renewbuffer(char *buff);
int		ft_emptybuffer(char *buff);
size_t	ft_stlen(const char *str);
int		ft_iscinstr(char c, char const *str, size_t len);
char	*ft_strnew(size_t size);
char	*ft_stjoin(char *s1, char *s2);
int render_next_frame(t_vars *vars);
int ft_release(int keycode, t_vars *vars);
int	ft_exit(int keycode, t_vars *vars);
int	key_hook(int keycode, t_vars *vars);
void	map_parsing(char *path, t_parse *g_p);
void       ft_init_vars(t_vars *vars, t_parse *g_p);
int     ft_bitmap(t_vars *win, t_data *image);
void    bmp_print(t_vars *win, t_data *image, int fd);
void    bmp_header_2(t_vars *win, t_data *image, int fd);
void    bmp_header(t_vars *win, int fd);

#endif