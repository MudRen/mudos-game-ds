#include <room.h>
inherit ROOM;

void create()
{
 set("short","��a");
 set("long",@LONG
�o�̬O�A�ЮǪ��@���j��a�A��a�W�����Z���ν����C��A�O��
���Ψө񪪬��b���a��A��a�W���X���p�����b�b�]�C
LONG);
   set("exits",([ 
       "west":__DIR__"room27",
       "south":__DIR__"room21",
       "north":__DIR__"room23",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/small-cow":3,
     ]) );
   setup();
}            
