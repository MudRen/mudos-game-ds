#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", HIC"七夕情緣"NOR);
  set ("long", @LONG
一陣香甜的氣味把你吸引到這特別的店面前，店內正站著一個漂亮的仙
女，正對你甜甜的笑著，你環顧四周，發現吸引你來的香味，是仙女親手做
的巧克力，那誘人的甜香，讓你恨不得馬上買下來嘗嘗。
LONG);

  set("no_clean_up", 1);
  set("exits", ([ /* sizeof() == 1 */
"down" : "/open/world1/tmr/area/inn_3f", 
]));
 set("objects", ([ /* sizeof() == 1 */
 __DIR__"seller" : 1,
]));
  setup();
  
}

