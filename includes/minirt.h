/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:58:33 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/14 15:44:29 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "execution.h"
# include "libft.h"
# include <fcntl.h> // for open, close
# include <math.h>  // for math functions
# include <stdbool.h>
# include <stdio.h>  // for printf, perror
# include <stdlib.h> // for malloc, free, exit
# include <string.h> // for strerror
# include <unistd.h> // for read, write, close
# define DLIMIT 2000 // DIAMETERS
# define NDLIMIT 0
# define RT_CHARSET "-., \n"
# define POS_XYZLIMIT 1200.0
# define NEG_XYZLIMIT -800.0

typedef t_list			t_file;
typedef struct s_ambient
{
	bool				set;
	bool				unique;
	float				ratio;
	int					rgb[3];
}						t_amb;

typedef struct s_camera
{
	bool				set;
	bool				unique;
	float				x;
	float				y;
	float				z;
	float				ox;
	float				oy;
	float				oz;
	int					fov;
}						t_camera;

typedef struct s_light
{
	bool				set;
	bool				unique;
	float				x;
	float				y;
	float				z;
	float				brightness;
}						t_light;

typedef struct s_sphere
{
	int					type;
	float				x;
	float				y;
	float				z;
	float				diameter;
	int					rgb[3];
	struct s_sphere		*next;
}						t_sphere;

typedef struct s_plane
{
	int					type;
	float				x;
	float				y;
	float				z;
	float				ox;
	float				oy;
	float				oz;
	int					rgb[3];
	struct s_plane		*next;
}						t_plane;

typedef struct s_cylinder
{
	int					type;
	float				x;
	float				y;
	float				z;
	float				ox;
	float				oy;
	float				oz;
	float				diameter;
	float				height;
	int					rgb[3];
	struct s_cylinder	*next;
}						t_cylinder;

typedef struct s_data
{
	struct s_ambient	ambient;
	struct s_camera		camera;
	struct s_light		light;
	struct s_sphere		*sphere;
	struct s_plane		*plane;
	struct s_cylinder	*cylinder;
}						t_data;

// bbg
void					bigbridge(t_data *data, t_scene *sc);
float					ft_atof(const char *nptr);
int						fill_file_copy(int fd, t_file **file_copy);
t_file					*copy_file(int fd);
int						handle_file_error(int argc, char **argv);
int						check_file_ext(char *str, char *sub);
void					clean_content(t_file *rt);
void					remove_current(t_file **file_copy, t_file *current);
void					remove_nl(t_file **copy);
void					remove_space(t_file **copy);
int						remove_extra_spaces(char *str);
void					remove_nls(t_file **copy);
t_data					*init_data(void);
int						check_float(char *line, char end_char);
int						check_int(char *line, char end_char);
int						parse_file(t_file *copy, t_data *data);
// Uniques
int						ambient_parse(char *line, t_data *data);
int						camera_parse(char *line, t_data *data);
int						parse_aratio(int *cursor, char *line, t_data *data);
int						parse_argb(int *cursor, char *line, t_data *data);
int						parse_file(t_file *copy, t_data *data);
int						parse_line(char *line, t_data *data);
// cam
int						parse_orientation(int *cursor, char *line,
							t_data *data);
int						parse_camorientation(int *cursor, char *line,
							t_camera *camera, int i);
int						checkxyzlimit(int x, int y, int z);
int						parse_camera_coord(int *cursor, char *line,
							t_camera *camera, int i);
int						parse_coord(int *cursor, char *line, t_data *data);
int						parse_fov(int *cursor, char *line, t_data *data);
int						valid_orientation(float x, float y, float z);
// light
int						parse_lcoord(int *cursor, char *line, t_data *data);
int						light_parse(char *line, t_data *data);
int						parse_light_coord(int *cursor, char *line,
							t_light *light, int i);
// plane
int						plane_parse(char *line, t_data *data);
int						parse_pcoord(int *cursor, char *line, t_plane *current);
int						parse_pvect(int *cursor, char *line, t_plane *current);
int						parse_prgb(int *cursor, char *line, t_plane *current);
// sphere
int						parse_sphere_coord(int *cursor, char *line,
							t_sphere *current, int i);
int						parse_spcoord(int *cursor, char *line,
							t_sphere *current);
int						sphere_parse(char *line, t_data *data);
int						parse_diameter(int *cursor, char *line,
							t_sphere *current);
int						parse_sprgb(int *cursor, char *line, t_sphere *current);
// cylinder
int						parse_cyvect(int *cursor, char *line,
							t_cylinder *current);
int						parse_cycoord(int *cursor, char *line,
							t_cylinder *current);
int						parse_cyrgb(int *cursor, char *line,
							t_cylinder *current);
int						cylinder_parse(char *line, t_data *data);
t_cylinder				*get_current_cylinder(t_data *data);
int						parse_cymeasures(int *cursor, char *line,
							t_cylinder *current);
void					data_clean(t_data *data);
int						parse_cylinder_coord(int *cursor, char *line,
							t_cylinder *current, int i);
void					custom_err(int err);
void					big_bridge_sphere(t_data *data, t_objs **head,
							t_objs **last, t_objs **newobj);
void					head_updater(t_objs **head, t_objs **newobj,
							t_objs **last);

#endif
