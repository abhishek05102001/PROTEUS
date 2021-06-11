#include<reg51.h>
sbit M1P=P2^3;	  //MOTOR INPUT IN1
sbit M1N=P2^4;	  //MOTOR INPUT IN2
sbit M2P=P2^5;	  //MOTOR INPUT IN3
sbit M2N=P2^6;	  //MOTOR INPUT IN4
#define display_port P1      //Data pins connected to port 2 on microcontroller
sbit rs = P2^0;  //RS pin connected to pin 2 of port 3
sbit rw = P2^1;  // RW pin connected to pin 3 of port 3
sbit e =  P2^2;  //E pin connected to pin 4 of port 3
void msdelay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}
void lcd_cmd(unsigned char command)  //Function to send command instruction to LCD
{
    display_port = command;
    rs= 0;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}
void lcd_data(unsigned char disp_data)  //Function to send display data to LCD
{
    display_port = disp_data;
    rs= 1;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}
 void lcd_init()    //Function to prepare the LCD  and get it ready
{
    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD
    msdelay(10);
    lcd_cmd(0x0F);  // turn display ON, cursor blinking
    msdelay(10);
    lcd_cmd(0x01);  //clear screen
    msdelay(10);
    lcd_cmd(0x81);  // bring cursor to position 1 of line 1
    msdelay(10);
}
void main()
{	 
	  unsigned char X;
	  SCON=0X50;  //set start bit,stop bit and data bit
	  TMOD=0X20;   //intialize Timer
	  TH1=-3;	   //set baud rate=9600
	  TR1=1;	   //Start Serial Communication
	  lcd_init();
	  while(1)
	  {
	  		while(RI==0);
		    X=SBUF;
			RI=0;
			if(X=='f')		 //BOT MOVES FORWARD
			{
			   M1P=1;
			   M2P=1;
			   M1N=0;
			   M2N=0;
			   lcd_data('F');
			   lcd_data('O');
			   lcd_data('R');
			   lcd_data('W');
			   lcd_data('A');
			   lcd_data('R');
			   lcd_data('D');
			   msdelay(500);
			   lcd_cmd(0x01);
			}
		   if(X=='b')		 //BOT MOVES BACKWARD
			{
			   M1P=0;
			   M2P=0;
			   M1N=1;
			   M2N=1;
			   lcd_data('B');
			   lcd_data('A');
			   lcd_data('C');
			   lcd_data('K');
			   lcd_data('W');
			   lcd_data('A');
			   lcd_data('R');
			   lcd_data('D');
			   msdelay(500);
			   lcd_cmd(0x01);
			}
			if(X=='l')	 //BOT MOVES LEFT
			{
			   M1P=1;
			   M2P=0;
			   M1N=0;
			   M2N=1;
			   lcd_data('L');
			   lcd_data('E');
			   lcd_data('F');
			   lcd_data('T');
			   msdelay(500);
			   lcd_cmd(0x01);
			  
			  
			}
			if(X=='r')	 //BOT MOVES RIGHT
			{
			   M1P=0;
			   M2P=1;
			   M1N=1;
			   M2N=0;
			   lcd_data('R');
			   lcd_data('I');
			   lcd_data('G');
			   lcd_data('H');
			   lcd_data('T');
			   msdelay(500);
			   lcd_cmd(0x01);
			  
			  
			}
			if(X=='s')	 //BOT STOP
			{
			   M1P=0;
			   M2P=0;
			   M1N=0;
			   M2N=0;
			   lcd_data('S');
			   lcd_data('T');
			   lcd_data('O');
			   lcd_data('P');
			   msdelay(500);
			   lcd_cmd(0x01);
			  
			}

	  }
	  

}