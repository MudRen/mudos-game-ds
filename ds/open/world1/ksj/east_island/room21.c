#include <room.h>
inherit ROOM;

void create()
{
 set("short","��a");
 set("long",@LONG
�o�̬O�A�ЮǪ��@���j��a�A��a�W�����Z���ν����C��A�O��
���Ψө񪪬��b���a��A��a�W���X�������b�C�Y�Y��C
LONG);
   set("exits",([ 
       "east":__DIR__"room16",
       "west":__DIR__"room26",
       "north":__DIR__"room22",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/cow":2,
     ]) );
   setup();
}            
