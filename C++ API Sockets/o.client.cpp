 /*
На вход подаётся текстовый файл со строками вида номер, двоеточие, вопрос. Также указывается количество вопросов в билете. Вернуть тестовый файл с билетами, где вопросы случайно распределяются среди билетов и не повторяются в различных билетах.
g++ k.server.cpp -o ser.out | g++ o.client.cpp -o cli.cpp
./ser.out -a 127.0.0.1:1030 -m 127.0.0.1:1031 &
./cli.cpp -a 127.0.0.1:1031 -m 127.0.0.1:1030
Questions.txt 41
  */
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string>
#include <sys/types.h>
#include <sys/un.h>
#include <time.h>
#include <limits.h>
#include <vector>
#include <fstream>
#include <random>

using namespace std;

int parse_ip (char* ip, char* new_ip)
{
  
  int i = 0,k = 0,j = 0, flag = 0;
  char tmp [BUFSIZ];
  for (i=0; i<strlen(ip);i++)
    {
      if (ip[i] == ':') 
      {
        flag = 1;
        continue;
      }
      if (flag == 1)
          tmp[k++]=ip[i];
        else 
          new_ip[j++] = ip[i];
    }
    return atoi(tmp);
}

int parse_str(string original, string* new_s)
{
  int i = 0;
  string id;
  while (original[i] != ':')
  {
    id += original[i];
    i++;
  }
  original.erase(0,i+1);
  *new_s = original;
return stoi(id);
}

int main(int argc, char *argv[]) 
{
    ofstream in_f;
    ifstream base;
    int sockop = 0, sockmy = 0, n = 0, num_of_quest, connfd, i = 0, id;
    char recvBuff[BUFSIZ];
    string sendBuff;
    string curr_str;
    vector <string> quest;
    struct sockaddr_in op_addr;
    struct sockaddr_in my_addr;
    char file_addr [BUFSIZ];
    char ipi_oponent [BUFSIZ];
    char ipi_me [BUFSIZ];
    int port_id_oponent;
    int port_id_me;
    memset(recvBuff, '0',sizeof(recvBuff));
    memset(&op_addr, '0', sizeof(op_addr));

  in_f.open("Tickets.txt");
  base.open("Questions.txt");
  try
  {
    if ((!in_f.is_open()) || (!base.is_open()))
      throw "1.txt";
  }
  catch (string file)
  {
    cout << "Can`t open file for writing - " << file << endl;
    return 0;
  }
    if (argc != 5)      // -a 127.0.0.1:1030 -m 127.0.0.1:1031
    {
      cout << argc <<endl;
      perror("\n  Not enough or too much arguments! \n");
      exit(-2);
    } 
    if ((strcmp(argv[1], "-a")) || (strcmp(argv[3], "-m")))   // -c - server, -m - my
    {
      cout << argv[1] <<"  "<< argv[3] << endl;
      perror("\n Invalid arguments! \n");
      exit(-4);
    } 

    if((sockmy = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
      perror("\n Error : Cannot create my socket \n");
      exit(-1);
    } 

    port_id_oponent = parse_ip(argv[2], ipi_oponent);
    port_id_me =  parse_ip(argv[4], ipi_me);

    op_addr.sin_family = AF_INET;
    op_addr.sin_port = htons(port_id_oponent);
    op_addr.sin_addr.s_addr = inet_addr(ipi_oponent);

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port_id_me);
    my_addr.sin_addr.s_addr = inet_addr(ipi_me);

    cout << "Enter the name of file and number of questions:" << endl;
    cin >> file_addr >> num_of_quest;

    if (bind(sockmy, (struct sockaddr*)&my_addr, sizeof(my_addr)) < 0)
    {
      perror("\n Error : Cannot bind my socket \n");
      exit(-3);
    } 
    if(connect(sockmy, (struct sockaddr *)&op_addr, sizeof(op_addr)) < 0)
    {
       perror("\n Error : Connect Failed \n");
       exit(-1);
    }

    send(sockmy, to_string(num_of_quest).c_str(), strlen(to_string(num_of_quest).c_str()), 0);
    while(base)
    {
      string curr_q;
      getline( base, curr_str, '\n' );
      if (!base) break;
      id = parse_str(curr_str, &curr_q);
      //cout << curr_q << endl;
      send(sockmy, curr_q.c_str(), strlen(curr_q.c_str()), 0);
      usleep(200);
    }
    send(sockmy, "EOF", strlen("EOF"), 0);
    if (id % num_of_quest != 0) cout << "WARNING: The number of questions is not completely divided by the number of tickets. Someone will get fewer questions." << endl;
    while(1)
    {
      memset(&recvBuff, '0', sizeof(recvBuff));
      n = recv(sockmy, recvBuff, sizeof(recvBuff), 0);
      recvBuff[n]='\0';
      if (strcmp(recvBuff, "EOF") == 0)
        break;
      in_f << recvBuff << endl;
    }
    
  return 0;
}
