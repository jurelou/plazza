//
// NamedPipe.hpp for Project-Master in /home/louis/Documents/cpp_plazza/include
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 09:31:40 2017 jurczy_l
// Last update Thu Apr 27 18:39:27 2017 jurczy_l
//

#ifndef		NAMEDPIPE_HPP_
# define	NAMEDPIPE_HPP_

# include	<unistd.h>
# include	<sstream>
# include	<cstring>
# include	<string>
# include	<iostream>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fstream>
# include	"Order.hpp"
# include	"Fork.hpp"


#  define		WRITE		0
#  define		READ		1

class		NamedPipe
{
public:
  NamedPipe(int proc_id, int id);
  ~NamedPipe();


  void		write_pipe(const Order& data);
  Order		*read_pipe();
  
  void		operator>>(const Order &data);
  Order		*operator<<(Order *data);

private:
  std::string	_name;
  
  void		create_fifo(const std::string& name);
public:

  std::string	_out_str;
  std::fstream	_out;
};

#endif
