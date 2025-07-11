/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:35:56 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/12 17:07:51 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

/*static void put_a(t_scene *sc)
{
    sc->amb.count = 1;
	sc->amb.ratio = 1;
	sc->amb.col.x = 64;
	sc->amb.col.y = 64;
	sc->amb.col.z = 64;
}

static t_light *light_alloc(t_scene *sc)
{
    t_light *new_light;

	new_light = malloc(sizeof(t_light));
	if (new_light == NULL)
		ft_err("allocation failed\n");
    new_light->next = sc->light;
	sc->light = new_light;
	return (new_light);
}
static void put_c(t_scene *sc)
{

	sc->cam.count++;
	sc->cam.cen.x = 0;
	sc->cam.cen.y = 1;
	sc->cam.cen.z = -3;

    sc->cam.dir.x = 0;
    sc->cam.dir.y = 0;
    sc->cam.dir.z = 1;

	sc->cam.fov = 70;
}

static void put_l(t_scene *sc)
{
	t_light *new;
	new = light_alloc(sc);
	new->src.x = 0 + 0.0001;
	new->src.y = 1 + 0.0001;
	new->src.z = 0 + 0.0001; 
	new->ratio = 1;
	new->col.x = 255;
	new->col.z = 255;
	new->col.z = 255;
}

t_objs *alloc_obj(t_vec dir, t_vec center, t_vec color, t_vec d, int type)
{
	t_objs *new = malloc(sizeof(t_objs));
	if (new == NULL)
		return NULL;
	new->type = type;
	new->col = color;
	new->cen = center;
	new->dir = dir;
	new->p = d;
	new->next = NULL;
    new->prev = NULL;
	return(new);
}

void make_list(t_objs **head, t_vec dir, t_vec center, t_vec color, t_vec d, int type)
{
	t_objs *newobj = alloc_obj(dir, center, color, d, type);
	if (newobj == NULL)
		return ;
	if (*head == NULL)
		{*head = newobj;
			return ; 
		}
		
	t_objs *last = *head;
	while (last->next != NULL) {
        last = last->next;
    }
	last->next = newobj;
	newobj->prev = last;
}

int	main()
{
	t_scene	*sc;


	sc = calloc(sizeof(t_scene), 1);
	if (sc == NULL)
		return 0;
	put_l(sc);
	put_a(sc);
	put_c(sc);
	
	t_vec dir = make_vec(0,0,0);
	t_vec center = make_vec(-0.5, 0.25, 0);
	t_vec color  = make_vec(255, 80, 80);
	t_vec d  = make_vec(0.5, 0, 0);
	int type = SP;
	make_list(&sc->objs, dir, center, color,d, type);

		t_vec a = make_vec(0,0,0);
	t_vec b = make_vec(0.5, 0.25, -0.5);
	t_vec e  = make_vec(80, 255, 80);
	t_vec r  = make_vec(0.5, 0, 0);
	int y = SP;
	make_list(&sc->objs, a, b, e, r, y);

	/*	t_vec B = make_vec(0,0,0);
	t_vec E = make_vec(0.5, 0.5, 0.5);
	t_vec R  = make_vec(80, 80, 255);
	t_vec A  = make_vec(1, 0, 0);
	int Y = SP;
	make_list(&sc->objs, B, E, R, A, Y);


	t_vec di = make_vec(0,1,0);
	t_vec c = make_vec(0, 0, 0);
	t_vec co  = make_vec(128, 128, 128);
	t_vec D  = make_vec(0, 0, 0);
	int t = PL;
	make_list(&sc->objs, di, c, co,D, t);

		t_vec dp = make_vec(0,-1,0);
	t_vec dc = make_vec(0, 2, 0);
	t_vec dr  = make_vec(128, 128, 128);
	t_vec dd  = make_vec(0, 0, 0);
	int dt = PL;
	make_list(&sc->objs, dp, dc, dr, dd, dt);

		t_vec d1 = make_vec(-1,0,0);
	t_vec d2 = make_vec(1, 0, 0);
	t_vec d3  = make_vec(255, 20, 20);
	t_vec d4  = make_vec(0, 0, 0);
	int d5 = PL;
	make_list(&sc->objs, d1, d2, d3,d4, d5);

		t_vec a1 = make_vec(1,0,0);
	t_vec a2 = make_vec(-1, 0, 0);
	t_vec a3  = make_vec(20, 255, 20);
	t_vec a4  = make_vec(0, 0, 0);
	int a5 = PL;
	make_list(&sc->objs, a1, a2, a3,a4, a5);



	/*t_vec i = make_vec(0,0,1);
	t_vec C = make_vec(50, 0, 20.6);
	t_vec col  = make_vec(10, 0, 128);
	t_vec Da  = make_vec(14.2, 21.42, 0);
	int ty = CY;
	make_list(&sc->objs, i, C, col,Da, ty);


	t_vec c1 = make_vec(1,0,0);
	t_vec c2 = make_vec(0.5, 0.5, 0.5);
	t_vec c3  = make_vec(10, 0, 255);
	t_vec c4  = make_vec(1.2, 10, 0);
	int c5 = CY;
	make_list(&sc->objs, c1, c2, c3,c4, c5);


		t_vec ni = make_vec(0,0,-1);
	t_vec nC = make_vec(0, 0, 1);
	t_vec ncol  = make_vec(128, 128, 128);
	t_vec nDa  = make_vec(0, 0, 0);
	int nty = PL;
	make_list(&sc->objs, ni, nC, ncol,nDa, nty);*
	sc->selected = sc->objs;//for object dinamique movement
	render_miniRT(sc);
	return (0);
}*/


sc->selected = sc->objs;//for object dinamique movement
render_miniRT(sc);
