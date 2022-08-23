#ifndef _QX_A11_H
#define _QX_A11_H

sbit Left_moto_pwm = P1^5; //为1 左电机使能
sbit IN1 = P1^4; //为1 左电机正转
sbit IN2 = P1^3; //为1 左电机反转
sbit IN3 = P1^2; //为1 右电机反转
sbit IN4 = P1^1; //为1 右电机正转
sbit Right_moto_pwm = P1^0; //为1 右电机使能
sbit IRIN=P3^2;
sbit LED1=P1^6;
sbit LED2=P1^7;
sbit han=P0^1;
sbit KEY = P3^3;
sbit beep = P2^2;//蜂鸣器

#define left_motor_stops	IN1 = 0, IN2 = 0//左电机停止
#define right_motor_stops	IN3 = 0, IN4 = 0//右电机停止

#define left_motor_go		IN1 = 1, IN2 = 0//左电机正传
#define left_motor_back		IN1 = 0, IN2 = 1//左电机反转
#define right_motor_go		IN3 = 0, IN4 = 1//右电机正传
#define right_motor_back	IN3 = 1, IN4 = 0//右电机反转

#endif