#include "LocalIncludeFile.h"
typedef unsigned char byte ;
static int TFI_HN_GetCommandLen ( byte* command )
{
	return command [ 2 ] ;
}
static byte HN_BBC ( byte* command )
{
	int len = 0 ;
	int i ;
	byte bbc = 0 ;
	len = TFI_HN_GetCommandLen( command )-1 ;
	for ( i = 0 ; i < ( len ) ; i++ )
	{
		echo("comman%d:%2x ",i,command[i]);
		bbc ^= command[i];
	}
	echo("commanbbc:%2x ",bbc);
	command [ len ] = bbc ;
	return bbc ;
}
static byte getValue ( int v , int min , int max )
{
	int i , x ;
	i = min < max ? min : max ;
	x = min > max ? min : max ;
	return ( v < i ? i : ( v > x ? x : v ) ) ;
}
static byte * show ( byte* command , int lane , int ld ,  char * str )
{
	int len = 0 ;
	byte *p ;
	len = strlen ( str ) ;
	memset ( command , 0x00 , 95 ) ;
	command [ 0 ] = 0xFF ;
	command [ 1 ] = 0xDC ;
	command [ 2 ] = 23 ;
	command [ 3 ] = 'D' ;
	command [ 4 ] = getValue(ld,0,0xff) ;
	command [ 5 ] = getValue(lane,1,6) ;
	p = &command [ 6 ] ;
	strncpy ( p , str , len<=16?len:16 ) ;
	HN_BBC(command) ;
	serial_write(LED_COM,command  ,TFI_HN_GetCommandLen( command ) ) ;
	usleep(10000*25);
	return command;
}
void   TFI_HN_clean ( )
{
	byte command[95];	
	int ret = 0;
	memset ( command , 0x00 , 95 ) ;
	command [ 0 ] = 0xFF ;
	command [ 1 ] = 0xDC ;
	command [ 2 ] = 5 ;
	command [ 3 ] = 'C' ;
	HN_BBC(command) ;
	ret = serial_write(LED_COM,command  ,TFI_HN_GetCommandLen( command )) ;
	usleep(10000*25);
}


void  TFI_HN_LedShow (   int CarType , int charge )
{	
	byte command[95];
	byte str1 [ 90 ] , str2 [ 90 ] ;
	sprintf ( str1 , " 车型:%4d 型车" , CarType ) ;
	sprintf ( str2 , " 金额:%4d 元  " , charge ) ;
	show ( command , 1 , 255 , str1 ) ;
	usleep(10000*25);
	show ( command , 2 , 255, str2 ) ;
	//15027745315
}


