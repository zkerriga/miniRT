/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_definition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:52:46 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/06 18:52:49 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "func.h"

static void		setup_ambient(t_rgbvec *dest, t_rgbvec obj_color, t_rgbvec ambient, float bright)
{
	dest->r = bright * ambient.r * obj_color.r;
	dest->g = bright * ambient.g * obj_color.g;
	dest->b = bright * ambient.b * obj_color.b;
}

/*
** The function gets the point where the ray collides with the object and
** the object. Next, the function determines how the object's color
** should change and returns an integer of the color.
** The function must clear the point that was created for it!
*/

int		color_definition(t_scene *scene, t_any_object *obj, t_point *point)
{
	t_rgbvec	ambient;
	t_rgbvec	diffuse;
	t_light		*light;
	t_list		*list;

	setup_ambient(&color, obj->color, scene->ambient->color, scene->ambient->light_ratio);
	list = scene->lights;
	while (list)
	{
		//color find work
		list = list->next;
	}
	free(point);
	return (color_to_int(color));
}
