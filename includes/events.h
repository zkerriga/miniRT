/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 07:04:47 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/25 07:04:49 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "scene.h"
# include "render.h"

# define RIGHT (2)
# define LEFT (1)
# define NONE (0)

# define K_ESCAPE (0xff1b)
# define K_RIGHT (0xff53)
# define K_LEFT (0xff51)

int		key_handler(int keycode, t_scene *scene);
int		close_handler(t_scene *scene);

#endif
