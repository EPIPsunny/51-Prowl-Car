#include <reg52.h>
#include <QX_A11.h>
#include <intrins.h>
#include <song.h>

typedef  int u16;	  
typedef unsigned char u8;
unsigned char	pwm_val_left,pwm_val_right;	
unsigned char 	pwm_left,pwm_right;			

#define		PWM_DUTY		200			
#define		PWM_HIGH_MIN	70			
#define		PWM_HIGH_MAX	PWM_DUTY	

 
void forward(unsigned char LeftSpeed,unsigned char RightSpeed);//前进 
void left_run(unsigned char LeftSpeed,unsigned char RightSpeed);//左转  
void right_run(unsigned char LeftSpeed,unsigned char RightSpeed);//右转
void stop(void);//停车
void back(unsigned char LeftSpeed,unsigned char RightSpeed);//后退

u8 date;//蓝牙串口存储值

void wait(u16 i)
{
	while(i--);	
}

void UartConfiguration()  
{
    TMOD=0x20;  //定时器1方式2   
    TH1=0xfd;  	  //波特率9600
    TL1=0xfd;  
    TR1=1;      //启动定时器1     
    SM0=0;SM1=1;      //串口方式1         
    REN=1;      //允许接收   
    PCON=0x00;  //关倍频   
    ES=1;       //开串口中断

	TMOD |= 0x02;//定时器0方式2
	TH0 = 164;
	TL0 = 164;//100微秒
	TR0 = 1;//启动定时器0
	ET0 = 1;//允许定时器0中断

	IT1=1;      //下降沿触发
    EX1=1;      //打开外部中断1

	EA=1;       //开总中断   


}


void LoadPWM(void)
{
	if(pwm_left > PWM_HIGH_MAX)		pwm_left = PWM_HIGH_MAX;	
	if(pwm_left < PWM_HIGH_MIN)		pwm_left = PWM_HIGH_MIN;	
	if(pwm_right > PWM_HIGH_MAX)	pwm_right = PWM_HIGH_MAX;	
	if(pwm_right < PWM_HIGH_MIN)	pwm_right = PWM_HIGH_MIN;	//保险装置
	if(pwm_val_left<=pwm_left)		Left_moto_pwm = 1;  //左高
	else Left_moto_pwm = 0; 						    //左低
	if(pwm_val_left>=PWM_DUTY)		pwm_val_left = 0;	//溢出归零

	if(pwm_val_right<=pwm_right)	Right_moto_pwm = 1; //右高
	else Right_moto_pwm = 0; 							//右低
	if(pwm_val_right>=PWM_DUTY)		pwm_val_right = 0;	//溢出归零
}

   
void main(void)
{
	u8 symbol=0;//速度更改
	u8 lowspeed=100;
	u8 highspeed=180;
	u8 error=10;//左右轮实验误差
	han=0;//扬声器边沿触发，P0.1
	UartConfiguration();//定时器和中断初始化

	
	while(1)
	{
		if(date=='v')			  //速度
		  {
		    LED1=~LED1;
			symbol=!symbol;
			date=0;
		  }
		else if(date=='m') 		  //响团子大家族音乐,用P3.3（KEY）触发下降沿引发外部中断1
		{
		   KEY=0;
		   
		   wait(5000);
		   KEY=1;
		   date=0; 
		}
			
		else if(date=='h') 		  //“您已进入中华人民共和国领土”语音播报
		{
		   han=!han;
		   delay(2000);
		   han=!han;
		   date=0;
		}
		
		else if(date=='w')		  //前进
		{
		   if(symbol==0)
		   {
		     forward(lowspeed,lowspeed+error);
		   }
		   if(symbol==1)
		   {
		     forward(highspeed,highspeed+error);
		   }
		   date=0;
		}
		else if(date=='a')		   //左转
		{
		   if(symbol==0)
		   {
		     left_run(lowspeed,lowspeed+error);
		   }
		   if(symbol==1)
		   {
		     left_run(highspeed,highspeed+error);
		   }
		   date=0;
		}
		else if(date=='d')			//右转
		{
		   if(symbol==0)
		   {
		     right_run(lowspeed,lowspeed+error);
		   }
		   if(symbol==1)
		   {
		     right_run(highspeed,highspeed+error);
		   }
		   date=0;
		}
		else if(date=='s')		   //后退
		{
		   if(symbol==0)
		   {
		     back(lowspeed,lowspeed+error);
		   }
		   if(symbol==1)
		   {
		     back(highspeed,highspeed+error);
		   }
		   date=0;
		}
		else if(date=='p') 		  //停车
		{
		   stop();
		   wait(5000);
		   date=0;
		}


		
	}	
}

void forward(unsigned char LeftSpeed,unsigned char RightSpeed)
{
	pwm_left = LeftSpeed,pwm_right =  RightSpeed;//设置速度
	left_motor_go; //左电机前进
	right_motor_go; //右电机前进
}


void left_run(unsigned char LeftSpeed,unsigned char RightSpeed)
{
	pwm_left = LeftSpeed,pwm_right =  RightSpeed;
	left_motor_back; //左电机后退
	right_motor_go; //右电机前进	
}


void right_run(unsigned char LeftSpeed,unsigned char RightSpeed)
{
	pwm_left = LeftSpeed,pwm_right =  RightSpeed;
	right_motor_back;//右电机后退
	left_motor_go;    //左电机前进
}

void stop(void)
{
	left_motor_stops;
	right_motor_stops;
}
void back(unsigned char LeftSpeed,unsigned char RightSpeed)
{
	pwm_left = LeftSpeed,pwm_right =  RightSpeed;
	right_motor_back;//右电机后退
	left_motor_back;    //左电机前进
}


void timer0_int (void) interrupt 1
{
	 pwm_val_left++;
	 pwm_val_right++;
	 LoadPWM();//装载PWM输出
}

void Int1() interrupt 2		//当检测到P3^3口下降沿触发
{

  u16 num=300,i;
  LED2=~LED2;
  delay(1000);			   //消抖
  if(KEY==0)			   
  {

    music();
      
  }
}

void Uart() interrupt 4
{
    
    date=SBUF;        //取数值，在date里
    RI=0;			  //清标志位
 

	
}
