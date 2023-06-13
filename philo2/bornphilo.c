/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bornphilo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:51:06 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/13 12:37:48 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*get_last(t_philo **philos)
{
	t_philo	*curr;

	if (!*philos)
		return (NULL);
	curr = *philos;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

static t_philo	*create_philo(int i, t_data *data)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->philo = i + 1;
	pthread_mutex_init(&(new->fork_r), NULL);
	new->fork_l = 0;
	new->next = 0;
	new->data = data;
	return (new);
}

t_philo	**bornphilo(int nb_philo, t_data *data)
{
	int		i;
	t_philo	*last;
	t_philo	*new;
	t_philo	**philos;

	philos = malloc(sizeof(t_philo *));
	if (!philos)
		return (NULL);
	*philos = 0;
	i = 0;
	while (i < nb_philo)
	{
		new = create_philo(i, data);
		last = get_last(philos);
		if (!last)
			(*philos) = new;
		else
		{
			new->fork_l = &(last->fork_r);
			last->next = new;
		}
		i++;
	}
	if (i > 0)
		new->fork_l = &((*philos)->fork_r);
	return (philos);
}
