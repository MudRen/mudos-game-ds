#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name("那魯雷斯騎士團佈告欄",({"board",}));
        set("location","/u/l/lary/workroom");
        set("board_id","kni_board");
        set("long","那魯雷斯騎士團佈告欄\n");
        setup();
        set("capacity",50);
        replace_program(BULLETIN_BOARD);
}
