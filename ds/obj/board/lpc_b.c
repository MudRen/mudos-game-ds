#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIC"LPC 討論版" NOR, ({ "lpc board","board", "lpc" }));
        set("location", "/u/c/cominging/bookroom.c");
        set("board_id", "lpc");
        set("long","這是一個用來討論 LPC 的版版！\n");
        setup();
        set("capacity", 100);
        set("master",({ "cominging" }));
}

