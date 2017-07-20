//
// Process.cpp for Project-Master in /home/louis/Documents/cpp_plazza/src
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 08:19:20 2017 jurczy_l
// Last update Mon Apr 24 08:22:16 2017 jurczy_l
//

#include	"Process.hpp"

Process::Process()
{}
Process::~Process()
{}

int		Process::createProcess()
{ return (fork()); }
