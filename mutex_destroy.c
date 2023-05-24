/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:02:18 by svanmeen          #+#    #+#             */
/*   Updated: 2023/05/24 13:05:53 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_destroy(pthread_mutex_t *locks, int nb)
{
	int	i;
	
	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&locks[i]);
		i++;
	}
	free(locks);
}
