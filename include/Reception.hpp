//
// Orders.hpp for Project-Master in /home/louis/Documents/cpp_plazza/include
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 10:45:28 2017 jurczy_l
// Last update Wed Apr 26 11:30:43 2017 jurczy_l
//

#ifndef		RECEPTION_HPP_
# define	RECEPTION_HPP_

# include	<queue>
# include	<sstream>
# include	<vector>
# include	<fstream>
# include	<unistd.h>
# include	<fcntl.h>
# include	<string>
# include	<tuple>
# include	<iostream>
# include	"Order.hpp"
# include	"NamedPipe.hpp"
# include	"Process.hpp"

class		Reception
{
public:
  Reception();
  ~Reception();

  void		setNbThreads(int nb);
  int		getNbThreads() const;
  void		read_orders();
  void		parse_order(std::string str);

  void		send_order(Process *proc, Order *data);
  void		send_exit(Process *proc);

  Process	*create_process();

private:
  std::queue<Order *>	orders;
  int			nb_threads;
  int			_id;
  std::vector<Process *>	_processes;
};

#endif
