#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIC"深田恭子Fans留言板"NOR,({"board"}));
        set("location","/u/m/mulder/workroom.c");
        set("board_id", "mulder_b");
        set("long",
        "這是一塊深田恭子Fans專用的留言板。\n");
        setup();
        set("capacity",100);
        set("no_sac",1);
        replace_program(BULLETIN_BOARD);
}
