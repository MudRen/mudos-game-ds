#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name("天山千年不化冰", ({ "board" }) );
        set("location", "/u/d/dreamcast/workroom");
        set("board_id", "dreamcast");
        set("long",
                "這是一塊很大的冰塊...可以在上面刻字\n" );
        setup();
        set("capacity", 99);
}
