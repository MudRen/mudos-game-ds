#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("電子留言板",({"board"}));
        set("location","/open/world3/alickyuen/area/inn2.c");
        set("board_id", "alickyuen_inn2_b");
        set("long",
        "這是一塊電子留言板 你忍不住想要在上面留下你的建議。\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}

