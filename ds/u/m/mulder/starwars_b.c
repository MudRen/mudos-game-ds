#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIC"�P�y�j�ԯd���O"NOR,({"board"}));
        set("location","/u/m/mulder/starwars.c");
        set("board_id", "starwars_b");
        set("long",
        "�o���d���O�O���A�̯d�U�����P�Ԫ���ơC\n");
        setup();
        set("capacity",100);
        set("no_sac",1);
        replace_program(BULLETIN_BOARD);
}
