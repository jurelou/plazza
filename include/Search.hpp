//
// Search.hpp for plazza in /home/marmus_a/Documents/rendu/Y2/S2/CPP/cpp_plazza
// 
// Made by Augustin Marmus
// Login   <marmus_a@epitech.eu>
// 
// Started on  Tue Apr 25 11:09:02 2017 Augustin Marmus
// Last update Tue Apr 25 15:00:17 2017 Augustin Marmus
//

#include	<map>
#include	<regex>
#include	"Order.hpp"

class	Search
{
  
public:
  Search(const Order& order);
  ~Search();

  void		find();
  
private:

  const Order&	_order;
  std::regex _reg;
};
