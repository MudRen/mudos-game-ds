#include <ansi.h>  
inherit ROOM;
 
void create()
{
  set("short", "霧洞深處 - 無間小道");
  set("long", @LONG
霧茫茫的一片，在此黑暗的洞穴內，似乎有種極為恐怖的生物，
沙沙的聲響不斷的發出。你注意到這邊的霧氣更濃，還帶著嘔心的血
腥味，沉重的寂靜聲中，越加凸顯出你內心的恐懼。
LONG
  );
  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"snake-room3",
     "down" : "/open/world1/tmr/wujian/snake-room6d",
     ]));
  set("no_clean_up", 0);
  setup();
}


