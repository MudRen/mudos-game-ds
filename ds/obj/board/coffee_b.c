#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIY"星空"HIR"之"HIC"湖"NOR, ({ "star lake","lake" }) );
        set("location", "/u/c/coffee/workroom.c");
        set("board_id", "coffee_b");
          set("long",HIY"這是一片照映著星空的湖泊，它有著能記憶人們的話的神秘力量。"NOR );
        setup();
        set("capacity", 100);
       set("master",({ "coffee" }) );
       replace_program(BULLETIN_BOARD);
}

