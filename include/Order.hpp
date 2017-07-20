//
// Orders.hpp for Project-Master in /home/louis/Documents/cpp_plazza/include
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 10:58:37 2017 jurczy_l
// Last update Mon Apr 24 11:05:27 2017 jurczy_l
//

#ifndef		ORDER_HPP_
# define	ORDER_HPP_

# include	<string>

enum		Information
  {
    PHONE_NUMBER,
    EMAIL_ADDRESS,
    IP_ADDRESS
  };

class		Order
{
public:
  Order(std::string file, Information info);
  ~Order();

private:
  Information	_info;
  std::string	_file;
};

#endif
