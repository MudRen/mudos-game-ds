// Room: /u/c/chia/area/ch04
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "玄武大街");
  set ("long", @LONG
你一路南行,沿路瀏覽美景,不禁對這裡大感興趣,原來此處盛產玄武岩,是一種質地相當堅硬的岩石,而此道路便是以玄武岩來構成的,整條大街上滴塵不染,由此可見居民對它的愛護。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
"south" : __DIR__"ch09",
"north" : __DIR__"ch0",
]));

  setup();
  replace_program(ROOM);
}

