#include <uart.h>
u8 temp=1;
void main(void)
{
  u8 *b="�ɻ�����ӳ����\r\n�����̰ܵ��շ�\r\n�Կ������Ʋ���\r\n��֪�����Ҿ㶫\r\n";
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

/***���ڷ�����*******/
void UARTInterrupt(void) interrupt 4
{
    if(RI)
    {
      RI = 0;
			temp=1;
        //add your code here!
    }

}
