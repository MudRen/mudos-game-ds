#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIG"Naboo城留言板"NOR,({"board"}));
        set("location","/open/world3/mulder/area/naboo/middle.c");
        set("board_id", "naboo_b");
        set("long",
        "這是一塊用金屬做的留言板 你可以在上面留下你的建議。\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}