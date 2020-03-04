#include <ansi.h>
inherit MOBROOM;

void create()
{
  set("short", "幼龍塔"HIR"第一層"NOR);
  set("long", @LONG
進入此地後，發覺殺氣凜冽，有數道龍眼朝此襲擊來，讓人感到毛骨
悚然，殺氣騰騰，想趕快離開此地，到外呼吸新鮮空氣。
LONG);
  set("exits", ([
  "southwest" : __DIR__"room4",
  "northeast" : __DIR__"room6",
 ]));
  set("mob_amount",4);
  set("chance",99); 
  set("no_member",1);  set("mob_object",({
  __DIR__"npc/long-dragon",
}));
  set("no_clean_up",0);
  set("outdoor",0);
  setup();
}


