//
// test.cpp for plazza in /home/marmus_a/Documents/rendu/Y2/S2/CPP/cpp_plazza
// 
// Made by Augustin Marmus
// Login   <marmus_a@epitech.eu> and <louis.jurczyk@epitech.eu> and <romain.springerroy@gmail.com>
// 
// Started on  Mon Apr 24 13:28:17 2017 Augustin Marmus
// Last update Tue Apr 25 17:49:10 2017 Augustin Marmus
//

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<iostream>
#include	<unistd.h>

int	main(int ac,char **av)
{
  int fd;
  char	buff[50];
  int fd2;
  if (!mkfifo("./fifo", 0666))
    {
      fd = open("./fifo", O_WRONLY);
      fd2 = open("./fifo", O_RDONLY);
      write(fd, "toto", 4);
      buff[read(fd2, buff, 4)] = 0;
      std::cout << buff << std::endl;
      close(fd);
      close(fd2);
    }
}
