#include <room.h>
inherit ROOM;

void create()
{
 set("short","�A��");
 set("long",@LONG
�غ��_�l���A�СA�Ф����L�L�����A�`�񪺽_�l�H�۷L���j�L�
곧@�T�A�X�ӹA�ҥ��s�۸y���Ԧa�b�Ф�����C
LONG);
   set("exits",([ 
       "east":__DIR__"room24",
       "south":__DIR__"room28",
       "north":__DIR__"room30",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/farmer":2,
     ]) );
   setup();
}            
