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

 
void forward(unsigned char LeftSpeed,unsigned char RightSpeed);//ǰ�� 
void left_run(unsigned char LeftSpeed,unsigned char RightSpeed);//��ת  
void right_run(unsigned char LeftSpeed,unsigned char RightSpeed);//��ת
void stop(void);//ͣ��
void back(unsigned char LeftSpeed,unsigned char RightSpeed);//����

u8 date;//�������ڴ洢ֵ

void wait(u16 i)
{
	while(i--);	
}

void UartConfiguration()  
{
    TMOD=0x20;  //��ʱ��1��ʽ2   
    TH1=0xfd;  	  //������9600
    TL1=0xfd;  
    TR1=1;      //������ʱ��1     
    SM0=0;SM1=1;      //���ڷ�ʽ1         
    REN=1;      //�������   
    PCON=0x00;  //�ر�Ƶ   
    ES=1;       //�������ж�

	TMOD |= 0x02;//��ʱ��0��ʽ2
	TH0 = 164;
	TL0 = 164;//100΢��
	TR0 = 1;//������ʱ��0
	ET0 = 1;//����ʱ��0�ж�

	IT1=1;      //�½��ش���
    EX1=1;      //���ⲿ�ж�1

	EA=1;       //�����ж�   


}


void LoadPWM(void)
{
	if(pwm_left > PWM_HIGH_MAX)		pwm_left = PWM_HIGH_MAX;	
	if(pwm_left < PWM_HIGH_MIN)		pwm_left = PWM_HIGH_MIN;	
	if(pwm_right > PWM_HIGH_MAX)	pwm_right = PWM_HIGH_MAX;	
	if(pwm_right < PWM_HIGH_MIN)	pwm_right = PWM_HIGH_MIN;	//����װ��
	if(pwm_val_left<=pwm_left)		Left_moto_pwm = 1;  //���
	else Left_moto_pwm = 0; 						    //���
	if(pwm_val_left>=PWM_DUTY)		pwm_val_left = 0;	//�������

	if(pwm_val_right<=pwm_right)	Right_moto_pwm = 1; //�Ҹ�
	else Right_moto_pwm = 0; 							//�ҵ�
	if(pwm_val_right>=PWM_DUTY)		pwm_val_right = 0;	//�������
}

   
void main(void)
{
	u8 symbol=0;//�ٶȸ���
	u8 lowspeed=100;
	u8 highspeed=180;
	u8 error=10;//������ʵ�����
	han=0;//���������ش�����P0.1
	UartConfiguration();//��ʱ�����жϳ�ʼ��

	
	while(1)
	{
		if(date=='v')			  //�ٶ�
		  {
		    LED1=~LED1;
			symbol=!symbol;
			date=0;
		  }
		else if(date=='m') 		  //�����Ӵ��������,��P3.3��KEY�������½��������ⲿ�ж�1
		{
		   KEY=0;
		   
		   wait(5000);
		   KEY=1;
		   date=0; 
		}
			
		else if(date=='h') 		  //�����ѽ����л����񹲺͹���������������
		{
		   han=!han;
		   delay(2000);
		   han=!han;
		   date=0;
		}
		
		else if(date=='w')		  //ǰ��
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
		else if(date=='a')		   //��ת
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
		else if(date=='d')			//��ת
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
		else if(date=='s')		   //����
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
		else if(date=='p') 		  //ͣ��
		{
		   stop();
		   wait(5000);
		   date=0;
		}


		
	}	
}

void forward(unsigned char LeftSpeed,unsigned char RightSpeed)
{
	pwm_left = LeftSpeed,pwm_right =  RightSpeed;//�����ٶ�
	left_motor_go; //����ǰ��
	right_motor_go; //�ҵ��ǰ��
}


void left_run(unsigned char LeftSpeed,unsigned char RightSpeed)
{
	pwm_left = LeftSpeed,pwm_right =  RightSpeed;
	left_motor_back; //��������
	right_motor_go; //�ҵ��ǰ��	
}


void right_run(unsigned char LeftSpeed,unsigned char RightSpeed)
{
	pwm_left = LeftSpeed,pwm_right =  RightSpeed;
	right_motor_back;//�ҵ������
	left_motor_go;    //����ǰ��
}

void stop(void)
{
	left_motor_stops;
	right_motor_stops;
}
void back(unsigned char LeftSpeed,unsigned char RightSpeed)
{
	pwm_left = LeftSpeed,pwm_right =  RightSpeed;
	right_motor_back;//�ҵ������
	left_motor_back;    //����ǰ��
}


void timer0_int (void) interrupt 1
{
	 pwm_val_left++;
	 pwm_val_right++;
	 LoadPWM();//װ��PWM���
}

void Int1() interrupt 2		//����⵽P3^3���½��ش���
{

  u16 num=300,i;
  LED2=~LED2;
  delay(1000);			   //����
  if(KEY==0)			   
  {

    music();
      
  }
}

void Uart() interrupt 4
{
    
    date=SBUF;        //ȡ��ֵ����date��
    RI=0;			  //���־λ
 

	
}
