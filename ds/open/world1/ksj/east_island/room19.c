#include <room.h>
inherit ROOM;

void create()
{
 set("short","���E");
 set("long",@LONG
�o�̬O���l�̪��p���E�A���L�|�P�ˬO��z�ƦC�F���֦n�F��A
���Y�W�Y���h�l�����~�i�H�ӳo���Ӧn�����C
LONG
    );
   set("exits",([ 
       "east":__DIR__"room14",
   ]));

   set("no_clean_up",0);
   set("light",1);
   set("objects",([
      __DIR__"npc/store-keeper":1,
     ]));
   setup();
}            
