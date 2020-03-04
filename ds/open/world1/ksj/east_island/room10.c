#include <room.h>
inherit ROOM;

void create()
{
  set("short","新陰流道場");
  set("long",@LONG
這裡是一間寬廣的道場，成立迄今已有數十年之久，目前的師範
是柳生．星明，道場地板由於弟子每天的練習跟擦拭顯得光亮潔淨，
道場兩旁擺了許多練習用的竹刀跟護具，門生練習的呼喝聲不絕於耳
。
LONG);
  set("exits",([ 
      "west":__DIR__"room14",
     ]));
  set("no_clean_up",0);
  set("light", 1);
  set("objects",([
      __DIR__"npc/apprentice":3,
      __DIR__"npc/hoshiakari":1,
     ]) );
  setup();
}            
