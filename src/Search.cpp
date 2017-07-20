//
// Search.cpp for search in /home/marmus_a/Documents/rendu/Y2/S2/CPP/cpp_plazza
// 
// Made by Augustin Marmus
// Login   <marmus_a@epitech.eu>
// 
// Started on  Tue Apr 25 11:19:59 2017 Augustin Marmus
// Last update Fri Apr 28 15:09:50 2017 jurczy_l
//

#include	<regex>
#include	<fstream>
#include	<iostream>
#include	"Search.hpp"
#include	"Cipher.hpp"

Search::Search(const Order& order) : _order(order)
{
  switch (order.getInfo())
    {
    case EMAIL_ADDRESS:
      _reg = "[a-zA-Z0-9\\._-]+@[a-zA-Z0-9\\._-]+";
      break;
    case PHONE_NUMBER:
      _reg = "(([0-9]{2}\\ {1}){4}([0-9]{2}))|(([0-9]{2}){4}([0-9]{2}))";
      break;
    case IP_ADDRESS:
      _reg = "[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}";
      break;
    default:
      _reg = "";
      break;
    }
}

Search::~Search()
{}

void	Search::find()
{
  //lock mutex
  std::string	line = "";
  std::ifstream	file(_order.getFile(), std::ios::in);

  if (!file.good())
    {
      std::cout << "Can't open file \"" << _order.getFile() << "\"" << std::endl;
      return;
    }

  while (getline(file, line))
    {
      std::smatch res;
      //uint16_t	i;
      //uint16_t	tmp;

      while (std::regex_search(line, res, _reg))
	{
	  if (res.size() > 0)
	    std::cout << res[0] << std::endl;
	  line = res.suffix().str();
	}
      //      i = 0;
      // tmp = 65535u;
      // while (i < tmp)
      // 	{
      // 	  if (i < 26)
      // 	    {
      // 	      std::string *to_search = Cipher::decryptCaesar(line, i);
      // 	      while (std::regex_search(*to_search, res, _reg))
      // 		{
      // 		  if (res.size() > 0)
      // 		    std::cout << res[0] << std::endl;
      // 		  *to_search = res.suffix().str();
      // 		}
      // 	      delete to_search;
      // 	    }
      // 	  std::string *to_search = Cipher::decryptXor(line, &i);
      // 	  while (std::regex_search(*to_search, res, _reg))
      // 	    {
      // 	      if (res.size() > 0)
      // 		std::cout << res[0] << std::endl;
      // 	      *to_search = res.suffix().str();
      // 	    }
      // 	  delete to_search;
      // 	  i++;
      // 	}
    }
  //unlock
}
