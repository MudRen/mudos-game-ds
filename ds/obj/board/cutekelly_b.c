#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("�p�Y���d���O",({"board"}));
        set("location","u/c/cutekelly/workroom.c");
        set("board_id", "cutekelly_b");
        set("long",
        "������ܴN�j�n�����L�g�i�h�a���C\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}
