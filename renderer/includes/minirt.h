/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:36:40 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/12 15:45:09 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 1200
# define HEIGHT 800
# define EPS 0.000001
# define CY 1
# define PL 2
# define SP 3
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx_linux/mlx.h"

typedef struct s_img_data {
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

typedef struct t_cam
{
	t_vec	cen;
	t_vec	dir;
	double	fov;
	int		count;
}	t_cam;

typedef struct s_light
{
	t_vec			src;
	double			ratio;
	t_vec			col;
}	t_light;

typedef struct s_amb
{
	t_vec	col;
	double	ratio;
	int		count;
}	t_amb;

typedef struct s_objs
{
	int				type;
	t_vec			cen;
	t_vec			dir;
	t_vec			p;
	t_vec			col;
	t_vec			norm;
	struct s_objs	*next;
}	t_objs;

typedef struct s_scene
{
	t_vec	col;
	t_cam	cam;
	t_light	*light;
	t_amb	amb;
	t_objs	*objs;
}	t_scene;

typedef struct collector
{
	void				*adr;
	struct collector	*next;
}	t_collector;

/* camera */
typedef struct Camera_Setup
{
	t_vec		orig;
	t_vec		up;
	t_vec		right;
	t_vec		forward;
	double		height;
	double		width;
	double		aspect_r;
	double		theta;
}	t_camera;

typedef struct CamRay
{
	t_vec	origin;
	t_vec	dir;
}	t_CamRay;

/* rendring */
typedef struct render
{
	t_vars		vars;
	t_img_data	img;
	double		v;
	double		u;
	int			x;
	int			y;
	t_camera	cam;
	t_CamRay	ray_;
	t_vec		ray_col;
}	t_render;

// Intersection 

typedef struct sphere
{
	double	a;
	double	b;
	double	c;
	double	t;
	double	t1;
	double	t2;
	t_vec	oc;
}	t_sphere;

typedef struct cylinder
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
}	t_cylinder;


//vectors
void		null_vec(t_vec *v);
t_vec		get_vec(char *s);
t_vec		get_color(char *s);
t_vec		get_normalized(t_vec v);
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
void make_list(t_objs **head, t_vec dir, t_vec center, t_vec color, t_vec d, int type);
t_objs *alloc_obj(t_vec dir, t_vec center, t_vec color, t_vec d, int type);

/*rendring */
void		ft_render(t_scene *sc);
void    ft_err(char *err);

/* camera */
t_camera	set_camera(t_scene *sc);
t_CamRay	ray_primary(t_camera *cam, double v, double u);
t_vec		ray_at(t_CamRay *ray, double t);

/* intersections*/
double		take_min(double x, double y);
t_inter		find_inter(t_CamRay *ray, t_scene *sc);
double		inter_sphere(t_CamRay *ray, t_objs *sp);
double		inter_plane(t_CamRay *ray, t_objs *pl);
double		inter_cylinder(t_CamRay *ray, t_objs *cy);

/* mlx funct */
int			red_button(t_vars *vars);
int			handle_key(int key, t_vars *vars);
void		my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

// color
t_vec		add_coef(t_vec col1, t_vec col2, double ratio);
int			create_rgb(int r, int g, int b);
t_vec		add_color(t_vec col1, t_vec col2);
t_vec		ray_color(t_CamRay *ray, t_scene *sc);
t_vec		colorize(double r, double g, double b);
t_vec		diffuse(t_inter inter, t_light *light, double d);
int			shade(t_scene *sc, t_inter inter, t_light *light);

//surface normal
int			is_inside(t_vec ray, t_vec norm);
t_inter		spher_normal(t_inter hold, t_objs *obj, t_CamRay *ray);
t_inter		plane_normal(t_inter hold, t_objs *obj, t_CamRay *ray);
t_inter		cylinder_normal(t_inter hold, t_objs *obj, t_CamRay *ray);

#endif