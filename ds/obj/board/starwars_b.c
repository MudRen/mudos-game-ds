#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIC"星球大戰留言板"NOR,({"board"}));
        set("location","/u/m/mulder/starwars.c");
        set("board_id", "starwars_b");
        set("long",
        "這塊留言板是給你們留下有關星戰的資料。\n");
        setup();
        set("capacity",100);
        set("no_sac",1);
        replace_program(BULLETIN_BOARD);
}
