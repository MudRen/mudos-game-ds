#include <room.h>
inherit ROOM;

void create()
{
 set("short","�A��");
 set("long",@LONG
�o�䪺�A�и̺ؤF�\�h����A�����ڽ��B�p���ʡB���B�յ浥�A
�ݰ_�ӳ��ͪ����ܦn�A�@���C�A�C
LONG);
   set("exits",([ 
       "west":__DIR__"room28",
       "south":__DIR__"room22",
       "north":__DIR__"room24",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            
