//
// Thread.hpp for Project-Master in /home/louis/Documents/cpp_plazza
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 07:31:01 2017 jurczy_l
// Last update Thu Apr 27 20:27:32 2017 jurczy_l
//

#ifndef		PROCESS_HPP_
# define	PROCESS_HPP_

# include	<algorithm>
# include	<unistd.h>
# include	<vector>
# include	<sys/wait.h>
# include	<fcntl.h>
# include	<queue>
# include	"NamedPipe.hpp"
# include	"Thread.hpp"

class		Process
{
public:
  Process(int id, int);
  ~Process();

  void		setPipe(NamedPipe *data);
  void		run();

  void *print(void *lol);
  void		send_order();

  int		getId() const;
  int		getPid() const;
  NamedPipe	*getPipe() const;
  
  
private:
  std::vector<std::thread>	test;  
  std::queue<Order *>	_queue;
  std::vector<Thread*>	_threads;
  Fork			*_fork;
  int			_id;
  int			_pipe_id;
  NamedPipe		*_pipe;
};

#endif
