#include <ansi.h>

inherit BULLETIN_BOARD;



void create()

{

        set_name(HIC"月光返射鏡"NOR,({"moon of mirror","mirror"}));

        set("location", "/u/y/yunin/workroom");

        set("board_id","yunin_b");

        set("long",

        "是人都可以留言和灌水的板板。\n");

        setup();

        set("capacity",60);
}

