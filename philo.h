/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:46:03 by svanmeen          #+#    #+#             */
/*   Updated: 2023/03/30 16:23:02 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_arg
{
	int				val;
	pthread_mutex_t	lock;
	int				i;
}					t_arg;

#endif
