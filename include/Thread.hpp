//
// Thread.hpp for Project-Master in /home/louis/Documents/cpp_plazza
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 07:31:01 2017 jurczy_l
// Last update Fri Apr 28 11:53:17 2017 jurczy_l
//

#ifndef		THREAD_HPP_
# define	THREAD_HPP_

#include	<thread>
#include	"Order.hpp"
#include	"NamedPipe.hpp"



class		Thread
{
public:
  Thread(int proc_id, int id);
  ~Thread();
  Thread(const Thread& other);

  void		run(void (routine)(Thread& tr), Thread &tr);
  void		join();
  bool		isJoinable();
  bool		isActive();

  void		setActive(bool activ);
  NamedPipe	*getPipe() const;

  std::thread	_thread;

protected:
  NamedPipe	*_pipe;
  bool		_active;
};

void		routine(Thread& tr);

#endif
