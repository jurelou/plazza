//
// Order.cpp for Project-Master in /home/louis/Documents/cpp_plazza/src
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 10:59:26 2017 jurczy_l
// Last update Mon Apr 24 11:05:34 2017 jurczy_l
//

#include	"Order.hpp"

Order::Order(std::string file, Information info)
{
  _info = info;
  _file = file;
}

Order::~Order()
{}
