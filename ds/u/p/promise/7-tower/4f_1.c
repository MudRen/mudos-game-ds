#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", RED"七邪塔 "HIB"【"HIW"亞空間"HIB"】"NOR);
  set ("long", @LONG
一什麼東西都沒有，黑暗的地方，完全到達了無的狀態，前方也
不見任何路線，真不知道該怎麼走下去。
LONG
);
  set("exits", ([
  "east" : __DIR__"4f_2",
  "north" : __DIR__"4_1",
   ])); 
   
  set("no_clean_up", 0);
  
  setup();
 }



