#include <room.h>
inherit ROOM;

void create()
{
 set("short","��a");
 set("long",@LONG
�o�̬O�A�ЮǪ��@���j��a�A��a�W�����Z���ν����C��A�O��
���Ψө񪪬��b���a��A��a�W���X�������b�V���C
LONG);
   set("exits",([ 
       "east":__DIR__"room21",
       "west":__DIR__"room31",
       "north":__DIR__"room27",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/cock":1,
      __DIR__"npc/hen":2,
     ]) );
   setup();
}            
