//
// NamedPipe.hpp for Project-Master in /home/louis/Documents/cpp_plazza/include
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 09:31:40 2017 jurczy_l
// Last update Mon Apr 24 09:34:36 2017 jurczy_l
//

#ifndef		NAMEDPIPE_HPP_
# define	NAMEDPIPE_HPP_

#include	<unistd.h>

#define		WRITE		0
#define		READ		1

class		NamedPipe
{
public:
  NamedPipe(const std::string& name, int flag);
  ~NamedPipe();

private:
  std::string	_name;
  int		_fd;
};

#endif
