#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIC"時空記事板"NOR, ({ "board" }) );
        set("location", "/open/world3/meetroom");
        set("board_id", "future_b");
        set("long",     "這是給負責未來的巫師記事用的。 \n" );
        setup();
        set("capacity", 100);
          set("master",({ "morral","tmr" }) );

}
