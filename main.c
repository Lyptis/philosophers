/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:43:11 by svanmeen          #+#    #+#             */
/*   Updated: 2023/05/24 13:46:23 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*void	*sleeping(void *param)
{
	t_arg	arg;

	arg = *((t_arg *)param);
	pthread_mutex_lock(&(arg.lock));
	arg.val -= 1;
	printf("%d cookie left\n", arg.val);
	pthread_mutex_unlock(&(arg.lock));
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	*tid;
	t_arg		*arg;
	int		i;

	if (argc != 2)
		return (0);
	//arg = malloc(sizeof(arg));
	pthread_mutex_init(&arg->lock, NULL);
	tid = malloc(sizeof(tid) * atoi(argv[1]));
	arg->val = atoi(argv[1]);
	i = 0;
	while (i < atoi(argv[1]))
	{
		arg->i = i;
		pthread_create(&(tid[i]), NULL, &sleeping, arg);
		i++;
	}
	i = 0;
	while (i < atoi(argv[1]))
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&arg->lock);
}*/

int	main(int argc, char **argv)
{
	t_philo	philo;
	t_data	data;
	struct timeval	*start;

	if (argc < 4 || argc > 5)
		return (printf("philo : \x1B[31mInvalid args\n\x1B[0m"));
	data = parse(argv);
	philo.data = &data;
	gettimeofday(start, NULL);
	philo.start = start;
	simulate(&philo);
	mutex_destroy(data.lock, data.nb_philo);
	free(data.forks);
}
