/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:22:25 by mvisca            #+#    #+#             */
/*   Updated: 2024/02/03 12:23:43 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	take_forks(t_philo *philo)
{
	if (philo->chair % 2 == 0)
		ft_sleep(5, philo->t);
	pthread_mutex_lock(philo->fork_r);
	print_fork(philo);
	pthread_mutex_lock(&philo->fork_l);
	print_fork(philo);
	return (0);
}

static int	philo_eat(t_philo *philo)
{
	long long	now;

	now = getlong(philo->t, NOW, 0);
	pthread_mutex_lock(&philo->t->mtx_philo_meal);
	philo->last_meal = now;
	pthread_mutex_unlock(&philo->t->mtx_philo_meal);
	pthread_mutex_lock(&philo->t->mtx_philo_meal);
	philo->meals_count = philo->meals_count + 1;
	pthread_mutex_unlock(&philo->t->mtx_philo_meal);
	print_eat(philo);
	ft_sleep(getint(philo->t, TIME_EAT, 0), philo->t);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(&philo->fork_l);
	if (!p_hungry(philo, philo->t))
	{
		pthread_mutex_lock(&philo->t->mtx_hungry);
		philo->t->hungry_count -= 1;
		pthread_mutex_unlock(&philo->t->mtx_hungry);
		return (1);
	}
	return (0);
}

static int	philo_sleep(t_philo *philo)
{
	print_sleep(philo);
	ft_sleep(getint(philo->t, TIME_SLEEP, 0), philo->t);
	return (0);
}

int	philo_die(t_philo *philo)
{
	if (!pt_dead(philo->t))
	{
		pthread_mutex_lock(&philo->t->mtx_dead);
		philo->t->dead_count += 1;
		pthread_mutex_unlock(&philo->t->mtx_dead);
		print_die(philo);
	}
	return (0);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (getint(philo->t, COUNT_CHAIRS, 0) == 1)
	{
		print_fork(philo);
		ft_sleep(getint(philo->t, TIME_DIE, 0), philo->t);
		philo_die(philo);
		return (NULL);
	}
	while (!pt_dead(philo->t) && p_hungry(philo, philo->t))
	{
		take_forks(philo);
		philo_eat(philo);
		if (p_dead(philo, philo->t) && pthread_mutex_unlock(philo->fork_r))
			pthread_mutex_unlock(&philo->fork_l);
		if (!p_dead(philo, philo->t) && p_hungry(philo, philo->t))
			philo_sleep(philo);
		if (!p_dead(philo, philo->t) && p_hungry(philo, philo->t))
			print_think(philo);
	}
	pthread_mutex_lock(&philo->t->mtx_end);
	pthread_mutex_unlock(&philo->t->mtx_end);
	return (NULL);
}
