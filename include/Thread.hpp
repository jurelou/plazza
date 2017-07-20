//
// Thread.hpp for Project-Master in /home/louis/Documents/cpp_plazza
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 07:31:01 2017 jurczy_l
// Last update Mon Apr 24 08:18:50 2017 jurczy_l
//

#ifndef		THREAD_HPP_
# define	THREAD_HPP_

#include	<pthread.h>

class		Thread
{
public:
  Thread(void *(routine)(void *), void * = NULL);
  ~Thread();
  
  void		join();
  void		*getReturnValue() const;
  
private:
  pthread_t	_id;
  void		*rv;
};

#endif
