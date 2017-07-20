//
// Fork.hpp for Project-Master in /home/louis/Documents/cpp_plazza/src
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Tue Apr 25 13:56:08 2017 jurczy_l
// Last update Wed Apr 26 09:23:25 2017 jurczy_l
//

#ifndef		FORK_HPP_
# define	FORK_HPP_

# include	<unistd.h>
# include	<sys/wait.h>

class		Fork
{
public:
  Fork();
  ~Fork();

  bool		isSon() const;
  pid_t		getPid() const;
private:
  pid_t		_pid;
};

#endif
