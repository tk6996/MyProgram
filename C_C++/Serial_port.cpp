#define NDEBUG

#include <WinSock2.h>
#include <process.h>
#include <iostream>
#include <serial.hpp>

using namespace std;

int running=1;
DCB dcb;
HANDLE hnd;

int hexchar(char chr) {
  if ('0'<=chr && chr<='9')
    return chr-'0';
  if ('A'<=chr && chr<='F')
    return chr+10-'A';
  if ('a'<=chr && chr<='f')
    return chr+10-'a';
  running=0;
  return -1;
}

unsigned __stdcall serial_tx_thread(void* arg) {
  int count=0;
  char chr;
  while (running) {
    int msg=cin.get(); // converts 0x1a into EOF
    running=msg!=EOF;
    if (running)
      if (count) {
        chr+=hexchar(msg);
        int cnt=serial_send(hnd,&chr,1);
        running=cnt==1;
        count=0;
      } else {
        chr=hexchar(msg)<<4;
        ++count;
      }
  }
  return 0;
}

#define RX_BUFFER_SIZE 32

int main(int argc, char* argv[]) {
  if (2<argc) {
    serial_init(dcb,atoi(argv[2]),NOPARITY);
    hnd=serial_open(dcb,atoi(argv[1]));
    if (0<=(int)hnd) {
      void* arg=0;
      unsigned ret;
      _beginthreadex(0,0,serial_tx_thread,(void*) arg,0,&ret);      
      char msg[RX_BUFFER_SIZE];
      while (running) {
        int poll=serial_poll(hnd);
        if (0<poll) {
          poll=min(poll,RX_BUFFER_SIZE);
          int res=serial_read(hnd,msg,poll);          
          for (int c0=0;c0<res;++c0)
            printf("%02x",(unsigned char)msg[c0]);
          cout.flush();
        } else 
          Sleep(1L); // this is necessary otherwise cpu goes up        
      }
      serial_close(hnd);
    }
  }
  return 0;
}