/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:46:03 by svanmeen          #+#    #+#             */
/*   Updated: 2023/05/24 14:11:17 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

// typedef struct s_arg
// {
// 	int				val;
// 	pthread_mutex_t	lock;
// 	int				i;
// }					t_arg;

typedef struct s_data
{
	pthread_mutex_t	*lock;
	int				*forks;
	int				philo;
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				noe;
}				t_data;

typedef struct s_philo
{
	t_data			*data;
	struct timeval	*start;
}				t_philo;

void	simulate(t_philo *philo);
//mutex_destroy
void	mutex_destroy(pthread_mutex_t *locks, int nb);
//arg parsing
int		ft_atoi(const char *str);
t_data	parse(char **strs);

#endif
