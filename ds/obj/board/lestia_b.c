// lestia_b.c
inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
        set_name(HIR"絢"NOR""RED"爛"HIR"花"NOR""RED"語"NOR, ({ "lestia board","board" }) );
        set("location", "/u/l/lestia/workroom.c");
        set("board_id", "lestia_b");
        set("long",     "這是一個給要留給Lestia的人用的。\n" );
        setup();
        set("capacity", 50);

}

