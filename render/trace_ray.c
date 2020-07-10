/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:48:05 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/03 16:48:08 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "func.h"

static t_point	*get_point(t_point *camera, t_3dvector *ray, float t)
{
	t_point		*point;

	if (!(point = (t_point *)malloc(sizeof(t_point))))
	{
		free_gc(NULL);
		ft_exit(ENOMEM);
	}
	point->x = camera->x + ray->x * t;
	point->y = camera->y + ray->y * t;
	point->z = camera->z + ray->z * t;
	return (point);
}

int				trace_ray(t_scene *scene, t_point *cam, t_3dvector *ray)
{
	t_list			*objects;
	t_any_object	*any;
	float			t;
	float			t_min;
	t_any_object	*found;

	if (!(objects = scene->objects))
		return (BLACK);
	t_min = MAX_T;
	found = NULL;
	while (objects)
	{
		any = objects->content;
		if ((t = any->solve(any, cam, ray, *ray_lim(1.f, MAX_T))) > 0
			&& t < t_min)
		{
			t_min = t;
			found = any;
		}
		ray_lim(0, 0);
		objects = objects->next;
	}
	if (found)
		return (color_definition(scene, found, get_point(cam, ray, t_min)));
}
