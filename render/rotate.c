/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:39:27 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/13 18:39:34 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "func.h"

static void	create_ort_vec(t_3dvector *dest, t_3dvector *dir)
{
	if (dir->x != 0.f)
		set_point(dest, -(dir->z + dir->y) / dir->x, 1.f, 1.f);
	else if (dir->y != 0.f)
		set_point(dest, 1.f, -(dir->z + dir->x) / dir->y, 1.f);
	else
		set_point(dest, 1.f, 1.f, -(dir->y + dir->x) / dir->z);
	normalize(dest);
}

/*
** A call without a ray prepares the transformation matrix.
** A call from a ray applies the matrix to a ray.
** [x]   [xR(x) + yU(x) + zD(x)]
** [y] = [xR(y) + yU(y) + zD(y)]
** [z]   [xR(z) + yU(z) + zD(z)]
** R - a right vector, U - an up vector, D - a camera's direction
*/

t_3dvector	*rotate_ray(t_3dvector *ray, t_3dvector *dir, t_point *camera)
{
	t_3dvector			tmp;
	static t_3dvector	right;
	static t_3dvector	up;

	if (ray)
	{
		set_point(&tmp, -ray->x, ray->y, ray->z);
		set_point(ray, right.x * ray->x + up.x * ray->y + dir->x * ray->z,
					right.y * ray->x + up.y * ray->y + dir->y * ray->z,
					right.z * ray->x + up.z * ray->y + dir->z * ray->z);
		normalize(ray);
	}
	else
	{
		create_ort_vec(&right, dir);
		vprod(&up, &right, dir);
	}
	return (ray);
}
