/***	51单片机12T 串口程序
			时间：20181110 
			地点：凤达f522
			作者：Light
			*******/

/*** 串口中断使用注意事项：
												1、打开中断后，接受中断和发送中断会同时打开
												2、发送中断，当发送完 8bit既一个字节，就跳一次中断
												3、接收中断，当接收完 8bit既一个字节，就进一次中断
												
												所以，当发送函数中有 while（！TI）；TI=0；既有清除中断标志时，中断中就不用清除了；
												*******/

#include <STC89C5xRC.h>
typedef unsigned char u8;


void InitUART(void);
void SendOneByte(unsigned char c);
void SendStr(u8 *a);
void SendVar(int Var);