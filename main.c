/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:43:11 by svanmeen          #+#    #+#             */
/*   Updated: 2023/03/30 16:33:21 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*sleeping(void *param)
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
	t_arg	*arg;
	int		i;

	pthread_mutex_init(&arg.lock, NULL);
	tid = malloc(sizeof(tid) * atoi(argv[1]));
	arg.val = atoi(argv[1]);
	i = 0;
	while (i < atoi(argv[1]))
	{
		arg.i = i;
		pthread_create(&(tid[i]), NULL, &sleeping, arg);
		i++;
	}
	i = 0;
	while (i < atoi(argv[1]))
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&arg.lock);
}
