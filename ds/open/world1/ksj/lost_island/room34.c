#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "遺世島－"HIW"石林上"NOR);
        set("long", @LONG
這裡是一小片化石樹林的頂端，石林密集而高聳，你幾乎無法看
到樹下的東西，石林周圍都是陡峭的岩壁。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "southwest" : __DIR__"room33",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("no_auc", 1);
  set("objects",([
      __DIR__"npc/silver-dragon":1,
     ]));

        setup();
}
