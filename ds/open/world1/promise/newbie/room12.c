#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "幼龍塔"HIR"第二層"NOR);
  set("long", @LONG
進入此地後，發覺殺氣凜冽，有數道龍眼朝此襲擊來，讓人感到毛骨
悚然，殺氣騰騰，想趕快離開此地，到外呼吸新鮮空氣。
LONG);
  set("exits", ([
  "north" : __DIR__"room11",
  "south" : __DIR__"room13",
 ]));
  set("no_member",1); 
  set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/dragon-queen" : 1,
]));

    set("no_clean_up",0);
  set("outdoor",0);
  setup();
}

