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

int main(int argc, char *argv[]) 
{
    srand(time(NULL));
    int sockop = 0, sockmy = 0, n = 0, num_of_quest = 0, connfd, i = 0, curr_id = 0, one_ticket;
    char recvBuff[BUFSIZ];
    string sendBuff;
    ofstream out;
    struct sockaddr_in op_addr;
    struct sockaddr_in my_addr;
    char file_addr [BUFSIZ];
    char ipi_oponent [BUFSIZ];
    char ipi_me [BUFSIZ];
    int port_id_oponent;
    int port_id_me;
    memset(recvBuff, '0',sizeof(recvBuff));
    memset(&op_addr, '0', sizeof(op_addr));
    string Curr_q = "======== Ticket # ";

    if (argc != 3)      // -a 127.0.0.1:1030 -m 127.0.0.1:1031
    {
      cout << argc <<endl;
      perror("\n  Not enough or too much arguments! \n");
      exit(-2);
    } 
    if (strcmp(argv[1], "-m"))   // -m - my
    {
      cout << argv[1]  << endl;
      perror("\n Invalid arguments! \n");
      exit(-4);
    } 

    if((sockmy = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
      perror("\n Error : Cannot create my socket \n");
      exit(-1);
    } 

    port_id_me = parse_ip(argv[2], ipi_me);

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port_id_me);
    my_addr.sin_addr.s_addr = inet_addr(ipi_me);

    //cout << "Enter the name of file and number of questions:" << endl;
    //cin >> file_addr >> num_of_quest;

    if (bind(sockmy, (struct sockaddr*)&my_addr, sizeof(my_addr)) < 0)
    {
      perror("\n Error : Cannot bind my socket \n");
      exit(-3);
    } 
    listen(sockmy, 15);
    while(1) 
    {
        vector <string> quest;
        num_of_quest = 0;
        out.open("out.txt");
        try
        {
        if (!out.is_open())
          throw "out.txt";
        }
        catch (string file)
        {
          cout << "Can`t open file for writing - " << file << endl;
          return 0;
        }

      i = 0;
      connfd = accept(sockmy, (struct sockaddr*)NULL, NULL);
      memset(&recvBuff, '0', sizeof(recvBuff));
      n = recv(connfd, recvBuff, sizeof(recvBuff), 0);
      recvBuff[n]='\0';
      one_ticket = atoi(recvBuff);

        while (1)
        {
          memset(&recvBuff, '0', sizeof(recvBuff));
          n = recv(connfd, recvBuff, sizeof(recvBuff), 0);
          recvBuff[n]='\0';
          if (strcmp(recvBuff, "EOF") == 0)
          break;
          quest.push_back(string(recvBuff));
          //cout << quest.back() << endl;
          num_of_quest++;
        }
        usleep(500);
        for (int p = 0; p < num_of_quest; p++)
        {
          sendBuff.clear();
          
          if (i%one_ticket == 0)
          {
            send(connfd, (Curr_q+to_string((i/one_ticket+1))).c_str(), strlen((Curr_q+to_string((i/one_ticket+1))).c_str()), 0); 
            out << Curr_q+to_string((i/one_ticket+1)) << endl;
            //cout << "\t" << Curr_q+to_string((i/one_ticket+1)) << endl;
          }
          sendBuff = to_string(i%one_ticket+1);
          while(quest[curr_id] == "-" && !quest.empty())
                curr_id = rand() % num_of_quest;
          //sendBuff += "  # "  + to_string(curr_id+1);
          sendBuff += quest[curr_id]; 
          send(connfd, (sendBuff).c_str(), strlen((sendBuff).c_str()), 0); 
          out << sendBuff << endl;
          //if (!(string(sendBuff).empty())) cout << sendBuff << endl;
          quest[curr_id] = "-";
          i++;
          usleep(100);
         
        }
        send(connfd, "EOF", strlen("EOF"), 0);
        out.close();
        shutdown(connfd,2);
    }

    return 0;
}
