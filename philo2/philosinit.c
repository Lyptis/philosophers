/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:36:30 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/14 16:30:29 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	udead(t_philo *philo)
{
	bool	dead;

	pthread_mutex_lock(&(philo->data->deadlock));
	if (philo->data->dead == 1)
		dead = true;
	else
		dead = false;
	pthread_mutex_unlock(&(philo->data->deadlock));
	if (dead)
		return (1);
	return (0);
}

void	*life(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (gettime(0) < data->start)
		continue ;
	while(!udead(philo))
	{
		printf("%lu : %d alive\n", gettime(philo->data->start), philo->philo);
		msleep(philo->data->tte);
	}
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
	info->start = gettime(0) + info->nb_philo * 10;
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
