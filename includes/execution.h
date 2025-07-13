/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:36:40 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/13 08:58:54 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# define WIDTH 800
# define HEIGHT 800
# define EPSYLON 0.00000000001
#define M_PI       3.14159265358979323846

# define CY 1
# define PL 2
# define SP 3

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_data_exec {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_inter
{
	double	t;
	t_vec	col;
	t_vec	hit;
	t_vec	norm;
}	t_inter;

typedef struct s_cam
{
	t_vec	cen;
	t_vec	dir;
	double	fov;
	int		count;
}	t_cam;

typedef struct s_light_exec
{
	t_vec			src;
	double			ratio;
	t_vec			col;
}	t_light_exec;

typedef struct s_amb_exec
{
	t_vec	col;
	double	ratio;
	int		count;
}	t_amb_exec;

typedef struct s_objs
{
	int				type;
	t_vec			cen;
	t_vec			dir;
	t_vec			p;
	t_vec			col;
	t_vec			norm;
	struct s_objs	*next;
	struct s_objs	*prev;
}	t_objs;

/* camera */
typedef struct s_camera_exec
{
	t_vec		orig;
	t_vec		UP;
	t_vec		R;
	t_vec		forward;
	double		H;
	double		W;
	double		A_ration;
	double		O;
}	t_camera_exec;

typedef struct Ray
{
	t_vec	origin;
	t_vec	dir;
}	t_Ray;

/* rendring */
typedef struct render
{
	t_vars		vars;
	t_img_data	img;
	double		v;
	double		u;
	int			x;
	int			y;
	t_camera_exec	cam;
	t_Ray	ray;
	t_vec		ray_col;
}	t_render;

typedef struct s_scene
{
	t_vec	col;
	t_cam	cam;
	t_light_exec	light;
	t_amb_exec	amb;
	t_objs	*objs;
	t_objs	*selected;
	t_render render;
}	t_scene;

// Intersection 

typedef struct sphere_exec
{
	double	a;
	double	b;
	double	c;
	double	t;
	double	t1;
	double	t2;
	t_vec	oc;
}	t_sphere_exec;

typedef struct cylinder_exec
{
	double	a;
	double	b;
	double	c;
	double	t;
	double	t1;
	double	t2;
	double	delta;
	double	y0;
	double	y1;
	t_vec	oc;
	t_vec	normal;
}	t_cylinder_exec;


//vectors
void		null_vec(t_vec *v);
t_vec		take_vec(char *s);
t_vec		take_color(char *s);
t_vec		take_normalized(t_vec v);
void		normalize(t_vec *v);
double		get_norm2(t_vec v);
t_vec		sub_vec(t_vec u, t_vec v);
t_vec		add_vec(t_vec u, t_vec v);
t_vec		mult_vec(t_vec v, double a);
t_vec		vect_cross(t_vec u, t_vec v);
double		dot_product(t_vec u, t_vec v);
double		module_v(t_vec	v);
t_vec		div_vect(t_vec v, double a);
t_vec		make_vec(double x, double y, double z);
//void make_list(t_objs **head, t_vec dir, t_vec center, t_vec color, t_vec d, int type);
t_objs *alloc_obj(t_vec dir, t_vec center, t_vec color, t_vec d, int type);

/*rendring */
void		render_miniRT(t_scene *sc);
void    ft_err(char *err);
void	creat_img(t_render info, t_scene *sc);
void objs_rotation(int n, t_scene *sc);

/* camera */
t_camera_exec	set_camera(t_scene *sc);
t_Ray	ray_primary(t_camera_exec *cam, double v, double u);
t_vec		ray_at(t_Ray *ray, double t);
void cam_rotation(int n, t_scene *sc);

/* intersections*/
double		check_min(double x, double y);
t_inter		find_inter(t_Ray *ray, t_scene *sc);
double		inter_sphere(t_Ray *ray, t_objs *sp);
double		inter_plane(t_Ray *ray, t_objs *pl);
double		inter_cylinder(t_Ray *ray, t_objs *cy);
double	limit_cy(t_cylinder_exec inf, t_Ray *ray, t_objs *cy);

/* mlx funct */
int			red_button(t_vars *vars);
int			handle_key(int key, t_scene *sc);
void		my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

// color
t_vec		add_coef(t_vec col1, t_vec col2, double ratio);
int			create_rgb(int r, int g, int b);
t_vec		add_color(t_vec col1, t_vec col2);
t_vec		ray_color(t_Ray *ray, t_scene *sc);
t_vec		colorize(double r, double g, double b);
t_vec		diffuse(t_inter inter, t_light_exec *light, double d);
int			shade(t_scene *sc, t_inter inter, t_light_exec *light);

//surface normal
int			is_inside(t_vec ray, t_vec norm);
t_inter		spher_normal(t_inter hold, t_objs *obj, t_Ray *ray);
t_inter		plane_normal(t_inter hold, t_objs *obj, t_Ray *ray);
t_inter		cylinder_normal(t_inter hold, t_objs *obj, t_Ray *ray);

#endif