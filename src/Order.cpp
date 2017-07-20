//
// Order.cpp for Project-Master in /home/louis/Documents/cpp_plazza/src
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 10:59:26 2017 jurczy_l
// Last update Wed Apr 26 10:14:51 2017 jurczy_l
//

#include	"Order.hpp"

Order::Order(std::string file, Information info)
{
  _info = info;
  _file = file;
}

Order::~Order()
{}

const std::string&	Order::getFile() const
{return (_file);}

Information		Order::getInfo() const
{return (_info);}

void			Order::setFile(const std::string& file)
{ _file = file; }

void			Order::setInfo(const int& info)
{ _info = static_cast<Information>(info); }
