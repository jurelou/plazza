

//
// Orders.hpp for Project-Master in /home/louis/Documents/cpp_plazza/include
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 10:58:37 2017 jurczy_l
// Last update Thu Apr 27 19:55:41 2017 jurczy_l
//

#ifndef		ORDER_HPP_
# define	ORDER_HPP_

# include	<string>

enum		Information
  {
    PHONE_NUMBER,
    EMAIL_ADDRESS,
    IP_ADDRESS,
    EXIT,
    NONE
  };

class		Order
{
public:
  Order(std::string file, Information info);
  ~Order();
  const std::string&	getFile() const;
  Information		getInfo() const;

  void			setFile(const std::string& file);
  void			setInfo(const int& file);
private:
  Information	_info;
  std::string	_file;
};

#endif
