//
// Thread.cpp for Project-Master in /home/louis/Documents/cpp_plazza
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 07:31:45 2017 jurczy_l
// Last update Mon Apr 24 08:19:31 2017 jurczy_l
//

#include	"Thread.hpp"

Thread::Thread(void *(routine)(void *), void *param)
{ pthread_create(&this->_id, NULL, routine, param); }

Thread::~Thread()
{}

void		Thread::join()
{ pthread_join(this->_id, &this->rv); }

void		*Thread::getReturnValue() const
{ return this->rv; }
