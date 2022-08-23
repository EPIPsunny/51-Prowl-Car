#ifndef _QX_A11_H
#define _QX_A11_H

sbit Left_moto_pwm = P1^5; //Ϊ1 ����ʹ��
sbit IN1 = P1^4; //Ϊ1 ������ת
sbit IN2 = P1^3; //Ϊ1 ������ת
sbit IN3 = P1^2; //Ϊ1 �ҵ����ת
sbit IN4 = P1^1; //Ϊ1 �ҵ����ת
sbit Right_moto_pwm = P1^0; //Ϊ1 �ҵ��ʹ��
sbit IRIN=P3^2;
sbit LED1=P1^6;
sbit LED2=P1^7;
sbit han=P0^1;
sbit KEY = P3^3;
sbit beep = P2^2;//������

#define left_motor_stops	IN1 = 0, IN2 = 0//����ֹͣ
#define right_motor_stops	IN3 = 0, IN4 = 0//�ҵ��ֹͣ

#define left_motor_go		IN1 = 1, IN2 = 0//��������
#define left_motor_back		IN1 = 0, IN2 = 1//������ת
#define right_motor_go		IN3 = 0, IN4 = 1//�ҵ������
#define right_motor_back	IN3 = 1, IN4 = 0//�ҵ����ת

#endif