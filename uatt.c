/***    51��Ƭ��12T ���ڳ���
            ʱ�䣺20181110 
            �ص㣺���f522
            ���ߣ�Light
            *******/



/*** �����ж�ʹ��ע�����
                                                1�����жϺ󣬽����жϺͷ����жϻ�ͬʱ��
                                                2�������жϣ��������� 8bit��һ���ֽڣ�����һ���ж�
                                                3�������жϣ��������� 8bit��һ���ֽڣ��ͽ�һ���ж�
                                                
                                                ���ԣ������ͺ������� while����TI����TI=0����������жϱ�־ʱ���ж��оͲ�������ˣ�
                                                *******/
#include <uart.h>
#include <stdio.h>

/***���ڳ�ʼ��*******/
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
/***����һ���ֽ�*******/
void SendOneByte(unsigned char c)
{
    SBUF = c;
    while(!TI);
    TI = 0;
}
/***�����ַ���*******/
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

