
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIG"天地會新手板"NOR, ({ "sky newbie board","board" }) );
        set("location", "/open/world1/manto/sky2_1f/map_7_9");
        set("board_id", "sky2_1f_7_9_b");
        set("long",
                "這是一個天地會內提供新人自我介紹的留言板。\n" );
        setup();
        set("capacity", 99);
}
