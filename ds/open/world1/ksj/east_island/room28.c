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
       "east":__DIR__"room23",
       "south":__DIR__"room27",
       "north":__DIR__"room29",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            

