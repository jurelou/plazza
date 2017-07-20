//
// Orders.hpp for Project-Master in /home/louis/Documents/cpp_plazza/include
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 10:45:28 2017 jurczy_l
// Last update Mon Apr 24 11:26:22 2017 jurczy_l
//

#ifndef		RECEPTION_HPP_
# define	RECEPTION_HPP_

# include	<queue>
# include	<iostream>
# include	"Order.hpp"

class		Reception
{

public:
  Reception();
  ~Reception();

private:
  std::queue<Order>	orders;
};

#endif
