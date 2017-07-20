//
// main.cpp for Project-Master in /home/louis/Documents/cpp_plazza/src
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 07:43:10 2017 jurczy_l
// Last update Tue Apr 25 16:24:31 2017 jurczy_l
//

#include	"Reception.hpp"
#include	"Process.hpp"
#include	"Search.hpp"

int		main(int ac, char **av)
{
  // Order tmp("test.cpp", EMAIL_ADDRESS);
  // Search search(tmp);
  // search.find();
  if (ac != 2 || atoi(av[1]) <= 0)
    return (1);
  Reception	*launcher = new Reception;
  launcher->setNbThreads(atoi(av[1]));
  launcher->read_orders();
}
