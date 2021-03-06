#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "遺世島－"HIG"洞窟"NOR);
  set("long", @LONG
這裡是一個陰暗的洞窟，四周結滿蜘蛛網，地面散落許多骨骸，
角落暗處似乎有東西在窺探你，空氣中滿是屍味及霉味。
LONG
);
  set("exits", ([ /* sizeof() == 4 */
      "out" : __DIR__"room30",
     ]));
  set("no_clean_up", 0);
  set("no_auc", 1);
  set("light", 0);
  set("objects",([
      __DIR__"npc/eagle-bat":1,
      __DIR__"npc/ghost-spider":1,
      __DIR__"npc/dream-tapir":1,
      __DIR__"npc/eq/captain-corpse":1,
     ]) );
  setup();
}
