#include<song.h>
#include <reg52.h>
#include <QX_A11.h>
typedef unsigned char u8;
typedef unsigned int u16;

void delay(u16 i)
   {
    while(i--);
   }


void C1(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(96);
	}
   }
void D1(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(85);
	}
   }
void E1(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(76);
	}
   }
void F1(u16 n)
   {
    u16 i; 
    for(i=0;i<=n;i++)
	{
	beep=!beep;
	delay(72);
	}
   }
void G1(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(64);
	}
   }
void A1(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(57);
	}
   }
void B1(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(51);
	}
   }
void C2(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(48);
	}
   }
void D2(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(43);
	}
   }
void E2(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(38);
	}
   }
void F2(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(36);
	}
   }
void G2(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(32);
	}
   }
void A2(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(28);
	}
   }
void B2(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(25);
	}
   }
void C(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(192);
	}
   } 
void D(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(170);
	}
   }
void E(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(152);
	}
   }
void F(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(143);
	}
   }
void G(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(128);
	}
   }
void A(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(114);
	}
   }
void b(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(102);
	}
   }
void C0(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(385);
	}
   }
void D0(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(340);
	}
   }
void E0(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(303);
	}
   }
void f0(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(286);
	}
   }
void G0(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(255);
	}
   }
void A0(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(227);
	}
   }
void B0(u16 m)
   {
    u16 i; 
    for(i=0;i<=m;i++)
	{
	beep=!beep;
	delay(202);
	}
   }




void music(void)
{
      while(1)
	  {
	  	A1(500);
		    delay(2500);
		G1(500);
		    delay(2500);
		C2(1400);
		    delay(2500);
		C2(1400);
		    delay(2500);
		D2(1400);
		    delay(2500);
		D2(1400);
		    delay(2500);
		E2(1400);
		    delay(2500);
		C2(1400);
		    delay(2500);
		G1(1000);

		
		A1(500);
		    delay(2500);
		G1(500);
		    delay(2500);
		C2(1400);
		    delay(2500);
		C2(1400);
		    delay(2500);
		D2(1400);
		    delay(2500);
		D2(1400);
		    delay(2500);
		E2(1400);
		    delay(2500);
		C2(2500);
		    delay(2500);
	   //
		A1(500);
		    delay(2500);
		G1(500);
		    delay(2500);
		C2(1400);
		    delay(2500);
		C2(1400);
		    delay(2500);
		D2(1400);
		    delay(2500);
		D2(1400);
		    delay(2500);
		E2(1400);
		    delay(2500);
		C2(1400);
		    delay(2500);
		G1(1000);

		A1(500);
		    delay(2500);
		G1(500);
		    delay(2500);
		C2(1400);
		    delay(2500);
		C2(1400);
		    delay(2500);
		D2(1400);
		    delay(2500);
		C2(2500);
		    delay(50000);



		   

		A1(500);
		    delay(2500);
		G1(500);
		    delay(2500);
		C2(1400);
		    delay(2500);
		C2(1400);
		    delay(2500);
		D2(1400);
		    delay(2500);
		D2(1400);
		    delay(2500);
		E2(1400);
		    delay(2500);
		C2(1400);
		    delay(2500);
		G1(1000);

		
		A1(500);
		    delay(2500);
		G1(500);
		    delay(2500);
		C2(1400);
		    delay(2500);
		C2(1400);
		    delay(2500);
		D2(1400);
		    delay(2500);
		D2(1400);
		    delay(2500);
		E2(1400);
		    delay(2500);
		C2(2500);
		    delay(2500);
	   //
		A1(500);
		    delay(2500);
		G1(500);
		    delay(2500);
		C2(1400);
		    delay(2500);
		C2(1400);
		    delay(2500);
		D2(1400);
		    delay(2500);
		D2(1400);
		    delay(2500);
		E2(1400);
		    delay(2500);
		C2(1400);
		    delay(2500);
		G1(1000);

		A1(500);
		    delay(2500);
		G1(500);
		    delay(2500);
		C2(1400);
		    delay(2500);
		C2(1400);
		    delay(2500);
		D2(1400);
		    delay(2500);
		C2(2500);
		    delay(50000);
		F2(1000);
		E2(1000);
		C2(1000);
		A1(1200);
		C2(1000);
		D2(1000);
		A1(1000);
		   delay(1500);
		C2(1000);
		G1(1000);
		A1(1000);
		C2(1400);
		F2(1000);
		E2(1000);
		C2(1000);
		A1(1200);
		C2(1000);
		D2(1000);
		A1(1000);
		C2(3500);
		   delay(2500);


	 	F2(1000);
		E2(1000);
		C2(1000);
		A1(1200);
		C2(1000);
		D2(1000);
		A1(1000);
		C2(1000);
		G1(1000);
		A1(1000);
		C2(1000);
		G1(1000);
		C2(1000);
		D1(1300);

	  }
}