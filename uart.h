/***	51��Ƭ��12T ���ڳ���
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

#include <STC89C5xRC.h>
typedef unsigned char u8;


void InitUART(void);
void SendOneByte(unsigned char c);
void SendStr(u8 *a);
void SendVar(int Var);