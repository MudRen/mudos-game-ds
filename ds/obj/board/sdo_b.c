#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("夜神碑",({"board"}));
        set("location","/u/s/sdo/workroom.c");
        set("board_id", "sdo_b");
        set("long",
        "這是一塊大石頭，隱隱的發著白光，似乎可以在上頭寫字！？\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}
