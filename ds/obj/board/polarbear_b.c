#include <ansi.h>

inherit BULLETIN_BOARD;
void create()
{
        set_name(HIC"大冰塊"NOR, ({ "big ice","ice","board"  }) );
        set("location", "/u/p/polarbear/workroom.c");
        set("board_id", "polarbear_b");
        set("long","〝哇!你不禁地叫了出來\n"
"這是一快好大的冰塊喔！又平又滑，不過上面好像有刻\n"
"畫的痕跡\n" );
        setup();
        set("capacity", 100);

}
