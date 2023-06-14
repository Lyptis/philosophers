/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:36:30 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/14 13:05:10 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
}

void	join_philo(pthread_t *tid, int nb_philo)
{
	int		i;

	i = 0;
	while (i != nb_philo)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
}

void philos_init(t_philo **philos, t_data *info)
{
	t_philo		*curr;
	pthread_t	*tid;
	int			i;

	tid = malloc(sizeof(pthread_t) * info->nb_philo);
	i = 0;
	curr = *philos;
	info->start = gettime(0);
	while (i < info->nb_philo && curr)
	{
		if (i % 2 == 0)
			pthread_create(&(tid[i]), NULL, &life, curr);
		curr = curr->next;
		i++;
	}
	i = 0;
	curr = *philos;
	while (i < info->nb_philo && curr)
	{
		if (i % 2 != 0)
			pthread_create(&(tid[i]), NULL, &life, curr);
		curr = curr->next;
		i++;
	}
	join_philo(tid, info->nb_philo);
}
