#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIC"�`�Ю��lFans�d���O"NOR,({"board"}));
        set("location","/u/m/mulder/workroom.c");
        set("board_id", "mulder_b");
        set("long",
        "�o�O�@���`�Ю��lFans�M�Ϊ��d���O�C\n");
        setup();
        set("capacity",100);
        set("no_sac",1);
        replace_program(BULLETIN_BOARD);
}
