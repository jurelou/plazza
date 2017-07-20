//
// Mutex.hpp for Project-Master in /home/louis/Documents/cpp_plazza
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 07:21:51 2017 jurczy_l
// Last update Mon Apr 24 07:52:43 2017 jurczy_l
//

#ifndef		MUTEX_HPP_
# define	MUTEX_HPP_

#include	<pthread.h>

class		Mutex
{
public:
  Mutex();
  ~Mutex();

  int		lock();
  int		unlock();
  int		trylock();
  pthread_mutex_t	getId() const;

private:
  pthread_mutex_t _id;
};

#endif
