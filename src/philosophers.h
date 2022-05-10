/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:07:32 by vtorosya          #+#    #+#             */
/*   Updated: 2022/05/10 14:27:36 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int					id;
	int					ate_count;
	int					left_fork;
	int					right_fork;
	long long			last_meal;
	long long			philo_born_time;
	int					is_dead;
	pthread_t			thread;
	pthread_mutex_t		*thinking;
	struct s_state		*state;
}				t_philo;

struct	s_state
{
	int					nb;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_eat;
	pthread_mutex_t		*fork;
};

int			init_args(int argc, char **argv, struct s_state *state);
t_philo		**init_philo(struct s_state *state);
int			init_thread(struct s_state *state, t_philo **philo);
long long	timestamp(void);
void		action_print(t_philo *philo, char *str);
void		smart_sleep(long long time, struct s_state *state);
int			errors(int n);
void		*death_checker(void *args);

#endif
