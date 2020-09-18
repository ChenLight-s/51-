/***    51单片机12T 串口程序
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
#include <uart.h>
#include <stdio.h>

/***串口初始化*******/
void InitUART(void)
{
//    TMOD = 0x20;
//    SCON = 0x50;
//    TH1 = 0xF3;
//    TL1 = TH1;
//    PCON = 0x00;
//    EA = 1;
//    ES = 1;
//    TR1 = 1;
    TMOD = 0x20;
    SCON = 0x50;
    TH1 = 0xFD;
    TL1 = TH1;
    PCON = 0x00;
    EA = 1;
    ES = 1;
    TR1 = 1;
}
/***发送一个字节*******/
void SendOneByte(unsigned char c)
{
    SBUF = c;
    while(!TI);
    TI = 0;
}
/***发送字符串*******/
void SendStr(u8 *a)
{
    while(*a!=0)
    {
        SendOneByte(*a);
        a++;
    }
}
void SendVar(int Var)
{
     u8 temp[8];
    sprintf(temp,"%02x",Var);
    
    SendStr(temp);
}








#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

