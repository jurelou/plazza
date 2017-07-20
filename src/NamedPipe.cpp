//
// NamedPipe.cpp for Project-Master in /home/louis/Documents/cpp_plazza/src
// 
// Made by jurczy_l
// Login   <louis.jurczyk@epitech.eu>
// 
// Started on  Mon Apr 24 09:30:18 2017 jurczy_l
// Last update Fri Apr 28 14:03:18 2017 jurczy_l
//

#include	"NamedPipe.hpp"

NamedPipe::NamedPipe(int proc_id, int id)
{
  std::stringstream	stream;
  std::stringstream	_stream;

  if (id == -1)
    _stream << "/tmp/plazzaout" << proc_id;
  else
    _stream << "/tmp/plazza_thread_out" << proc_id << id;
  _out_str = _stream.str();
  if (mkfifo(_out_str.c_str(), 0666) != 0)
    exit (96);
  _out.open(_out_str.c_str(), std::ostream::out | std::ios::in);
}

NamedPipe::~NamedPipe()
{  remove(_out_str.c_str()); }

void		NamedPipe::create_fifo(const std::string& name)
{
  if (mkfifo(name.c_str(), S_IRUSR | S_IWUSR) != 0)
    exit(12);
}

void		NamedPipe::write_pipe(const Order& data)
{
  _out << data.getFile().c_str() << " " << std::to_string(data.getInfo()) << std::endl;
}

Order		*NamedPipe::read_pipe()
{
  Order		*data;
  std::stringstream	line;
  std::string	tmp;

  std::getline (_out, tmp);
  if (tmp.empty())
    return (nullptr);

  data = new Order("",NONE);
  line << tmp;
  line >> tmp;
  data->setFile(tmp);
  line >> tmp;
  data->setInfo(std::atoi(tmp.c_str()));
  if (data->getInfo() == EXIT)
    return (data = new Order("exit", EXIT));
  return (data);
}

void            NamedPipe::operator>>(const Order &data)
{  write_pipe(data); }

Order		*NamedPipe::operator<<(Order *data)
{
  (void)data;
  return (read_pipe());
}
