#include <room.h>
inherit ROOM;

void create()
{
  set("short","街道");
  set("long",@LONG
這裡是村中的街道，在這邊已經可以看到村子裡面的一些房屋及
建築，人來人往看起來很熱鬧，東邊是有名的新陰流道場，西邊有一
間小當舖。
LONG);
  set("exits",([ 
      "east":__DIR__"room10",
      "west":__DIR__"room19",
      "south":__DIR__"room13",
      "north":__DIR__"room15",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/asaka":1,
     ]) );
  setup();
}
