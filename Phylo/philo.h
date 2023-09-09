#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
    int id;
    int meals_to_eat;
    int *program_should_stop;
    struct timeval time_of_last_meal;
    int program_start;
    pthread_mutex_t *fork_left;
    pthread_mutex_t *fork_right;
    pthread_mutex_t *stop;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    struct s_global *global;
}   t_philo;

typedef struct s_global
{
    int nbrephilo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int meals_to_eat;
    struct timeval program_start;
    int program_should_stop;
    pthread_mutex_t *fork_mutex;
    t_philo *philo;
}   t_global;

int init_mutex(t_global *global);
int init_philo(t_global *global, int *philosophers_done);
int *init_global(char **argv, t_global *global, int *philosophers_done);
int *init_all(t_global *global, char **argv, int *philosophers_done, pthread_t *threads);
int parser_arg(char **argv, int argc);
void *philosopher(void *arg);
void free_all(t_global *global);
void *philosopher(void *arg);
int get_time_since_start(struct timeval program_start);
void init_threads(t_global *global, pthread_t *threads);
void philoalone(t_philo *philo);
void prisefourchette(t_philo *philo);
void mangeur(t_philo *philo);
void mort(t_philo *philo);
void sleeping(t_philo *philo);


#endif