#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
  set_name(HIC"仙月"HIG"璧"NOR, ({ "board" }) );
  set("location", "/open/world1/acme/area/moon/room9");
        set("long",
                "這是一個讓月族的Leader討論幫裡代誌的板。
\n" );
  set("board_id", "moon_room9_b");
  setup();
  set("capacity",99);
  set("master",({ "fofo" }));
}


