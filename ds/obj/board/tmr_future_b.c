#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"生活留言板"NOR,({"board"}));
        set("location","/open/world3/tmr/basic/hotel");
        set("board_id", "tmr_future_b");
        set("long",
        "一面大家用來交流的留言板，任何人有事都能在上面留言的。\n");
        setup();
        set("capacity",100);
 
}

