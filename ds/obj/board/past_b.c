#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(CYN"劍壁"NOR, ({ "sword board","board" }));
        set("location", "/open/world1/meetroom"); 
        set("board_id", "past_b");
        set("long","這是十分巨大的山壁, 上面布滿由劍氣刻成的文字..\n" );
        setup();
        set("capacity", 100);
        set("master",({ "linjack" }));

}
