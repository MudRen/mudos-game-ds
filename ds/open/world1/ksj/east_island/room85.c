#include <room.h>
inherit ROOM;

void create()
{
 set("short","竹林");
 set("long",@LONG
你所站的地方處於竹林之中，一眼望去四周都是翠綠的竹子，隨
著微風吹過發出咿咿啊啊的聲響，頭頂上不時有竹葉一邊旋轉一邊飄
落下來。
LONG);
   set("exits",([ 
       "east":__DIR__"room82",
       "west":__DIR__"room88",
       "south":__DIR__"room87",
       "north":__DIR__"room84",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            
