#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIR"司令官DOMY"HIW"的"MAG"好心情"HIW"留言板"NOR,({"board"}));
        set("location","/u/d/domy/workroom.c");
        set("board_id", "domy_b");
        set("long",
        "這個版版是為了寫寫筆記，吐槽用的。歡迎來留言ㄛ。\n");
        setup();
        set("capacity",100);
}

