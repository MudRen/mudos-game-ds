#include <path.h>
#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
    set_name(HIY"蟲蟲留言板"NOR, ({ "board" }));
        set("location","/u/s/superbug/workroom");
        set("board_id", "superbug_b");
    set("long","一塊快被蟲蟲吃玩的木板，上面似乎還可寫一些字。\n");
        setup();
        set("capacity", 60);
        set("master",({ "superbug" }));
}
