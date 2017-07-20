//
// Thread.cpp for Project-Master in /home/louis/Documents/cpp_plazza
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 07:31:45 2017 jurczy_l
// Last update Fri Apr 28 15:07:38 2017 jurczy_l
//

#include	<unistd.h>
#include	<thread>
#include	"Thread.hpp"
#include	"Search.hpp"

void		routine(Thread& tr)
{
  Order		*tmp;
  std::string	line, i, file;

  //std::cout << "=> thread " << tr._thread.get_id()<< " launched." << std::endl;
  while ((tmp = tr.getPipe()->read_pipe()))
    {
      tr.setActive(true);
      if (tmp->getInfo() == EXIT)
	return;
      // std::cout << "thread n°" << tr._thread.get_id():
      // std::cout << " execute "  << tmp->getFile() <<";" << tmp->getInfo() << std::endl;
      Search	search(*tmp);
      search.find();
      tr.setActive(false);
      delete tmp;
    }
  return ;
}

Thread::Thread(int proc_id, int id)
{
  _active = false;
  //std::cout << " + thread " << std::endl;
  _pipe = new NamedPipe(proc_id, id);
}

Thread::Thread(const Thread& other)
{
  _active = false;
  (void)other;
}

Thread::~Thread()
{
  if (this->isJoinable())
    this->join();
}

void		Thread::run(void (toto)(Thread& tr), Thread &tr)
{
  _thread = std::thread(toto, std::ref(tr));
}

void		Thread::join()
{  _thread.join(); }

bool		Thread::isJoinable()
{
  return (_thread.joinable());
}

NamedPipe	*Thread::getPipe() const
{ return(_pipe); }

bool		Thread::isActive()
{  return (_active); }

void		Thread::setActive(bool activ)
{ _active = activ; }
