#define RCCAHB1EN *((unsigned volatile int *) 0x40023830)
#define GPIODMOD *((unsigned volatile int *) 0x40020c00)
#define gpiodODR *((unsigned volatile int *) 0x40020c14)
unsigned int bcountname,bcoutsurname,name_led,surname_led;
void led_checker(){
	int sum_name=0;
	int sum_surname=0;
	int i=0;
	int j=0;
	char name[]="EMIRCAN"; // Write your name inside " "
	char surname[]="COSKUN";// Write your surname " "

		while(name[i]!='\0'){// Calculates name`s ascii value  and number of letters in name
			sum_name+=name[i];
			i++;
		}// while end
		bcountname=i;

	name_led=sum_name%4;// Led checker for your name

		while(surname[j]!='\0'){// Calculates surname`s ascii value  and number of letters in surname
			sum_surname+=surname[j];
			  j++;
		}

		bcoutsurname=j;// Led checker for your surname

	surname_led=sum_surname%4; //// Led checker for your surname

}
void delay(){// delay function for led blink
	int delay0 = 0xFDEAF;
	while (delay0--){}
}
void init_leds () {//Open clocks for GPIOD
	 	RCCAHB1EN = 0x8; //the necessary clock for the bus enable
}
void turn_name_on(){// turns on the led for associated with your name
	init_leds();
	if(name_led==0)// red
	{
		GPIODMOD |= 01<<28;
		gpiodODR |= 1<<14;
	}
	else if(name_led == 1) // blue
	{
		GPIODMOD |= 01<<30;
		gpiodODR |= 1<<15;
	}
	else if(name_led==2)// orange
	{
		GPIODMOD |= 01<<26;
		gpiodODR |= 1<<13;
	}
     else// 3 is green
     {
    	 GPIODMOD |= 01<<24;
    	 gpiodODR |= 1<<12;
     }
}
void turn_surname_on(){// turns on the led for associated with your surname
	init_leds();
		if(surname_led==0)//red
		{
			GPIODMOD |= 01<<28;
			gpiodODR |= 1<<14;
		}
		else if(surname_led == 1)//blue
		{
			GPIODMOD |= 01<<30;
			gpiodODR |= 1<<15;
		}
		else if(surname_led==2)//orange
		{
			GPIODMOD |= 01<<26;
			gpiodODR |= 1<<13;
		}
	     else//3 is green
	     {
	    	 GPIODMOD |= 01<<24;
	    	 gpiodODR |= 1<<12;
	     }
	}


void turn_name_off(){// turns off the led for associated with your name
	if(name_led==0)
		{
			gpiodODR &= 0<<14;// close red
		}
		else if(name_led == 1)
		{
			gpiodODR &= 0<<15; // close blue
		}
		else if(name_led==2)
		{
			gpiodODR &= 0<<13;// close orange
		}
	     else
	     {
	    	 gpiodODR &= 0<<12;// close green
	     }
}
void turn_surname_off(){// turns off the led for associated with your surname
	if(name_led==0)
			{
				gpiodODR &= 0<<14;// close red
			}
			else if(name_led == 1)
			{
				gpiodODR &= 0<<15; // close blue
			}
			else if(name_led==2)
			{
				gpiodODR &= 0<<13;// close orange
			}
		     else
		    {
		    	 gpiodODR &= 0<<12;// close green
		    }
}

void main(){
int i;
led_checker();
for (i=0;i!=bcountname;i++){
	turn_name_on();
	delay();
	turn_name_off();
	delay();
}
for (i=0;i<bcoutsurname;i++){//i!=x????????
	turn_surname_on();
	delay();
	turn_surname_off();
	delay();
}
}
