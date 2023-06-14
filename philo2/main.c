/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:34:37 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/14 15:17:49 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	**philo;
	t_data	*info;

	info = fill_data(argc, argv);
	philo = bornphilo(info->nb_philo, info);
	if (!philo)
		return (0);
	info->philo = philo;
	philos_init(philo, info);
	return (0);
}
