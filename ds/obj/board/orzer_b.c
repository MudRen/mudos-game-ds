#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIR"�O��"HIW"�d���O"NOR,({"orz board","board"}));
        set("location","/u/o/orzer/workroom.c");
        set("board_id", "orzer_b");
        set("long",
        "�o�O�@����O���p�������l �Цh�h�d�U��ĳ�C\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}

