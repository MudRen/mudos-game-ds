
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIG"天地會決策板"NOR, ({ "sky decision board","board" }) );
       set("location", "/open/world1/manto/sky2_2f/map_3_8");
       set("board_id", "sky2_2f_1_8_b");
        set("long","這是一個天地會內高層公佈策略討論所用的留言板。\n" );
        setup();
        set("capacity", 200);
}
