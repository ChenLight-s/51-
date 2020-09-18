#include <uart.h>
u8 temp=1;
void main(void)
{
  u8 *b="飞花两岸映船红\r\n百里榆堤半日风\r\n卧看满天云不动\r\n不知云与我俱东\r\n";
	u8 c[]="\r\n";
	
	InitUART();
	SendOneByte('3');
	SendStr(b);
	P0=0x21;	
	while(1)
	{
		if(temp==1)
		{
				SendOneByte(SBUF);
			
//			SendStr("P0= ");
//			SendVar(P0);
//			SendStr("\r\n");
//			SendStr("P1= ");
//			SendVar(P1);
//			SendStr("\r\n");
//			SendStr("P2= ");
//			SendVar(P2);
//			SendStr("\r\n");
//			SendStr("P3= ");
//			SendVar(P3);
//			SendStr("\r\n");
			temp=0;
		}
	}
}

/***串口服务函数*******/
void UARTInterrupt(void) interrupt 4
{
    if(RI)
    {
      RI = 0;
			temp=1;
        //add your code here!
    }

}
