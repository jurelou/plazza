//
// Fork.cpp for Project-Master in /home/louis/Documents/cpp_plazza/src
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Tue Apr 25 13:56:55 2017 jurczy_l
// Last update Wed Apr 26 09:24:07 2017 jurczy_l
//

#include	"Fork.hpp"

Fork::Fork()
{
  _pid=fork();
}

Fork::~Fork()
{
  int	status;
  waitpid(_pid, &status, 0);
}

pid_t		Fork::getPid() const
{ return(_pid); }

bool		Fork::isSon() const
{ return (_pid == 0); }
