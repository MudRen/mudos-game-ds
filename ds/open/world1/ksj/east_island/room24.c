#include <room.h>
inherit ROOM;

void create()
{
 set("short","�A��");
 set("long",@LONG
�غ��_�l���A�СA�Ф����L�L�����A�`�񪺽_�l�H�۷L���j�L�
곧@�T�A�A�H���b���q���䪺�����C
LONG);
   set("exits",([ 
       "west":__DIR__"room29",
       "south":__DIR__"room23",
       "north":__DIR__"room25",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/houjou":1,
     ]) );
   setup();
}            
