#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("�]���O",({"board"}));
        set("location","/u/s/sdo/workroom.c");
        set("board_id", "sdo_b");
        set("long",
        "�o�O�@���j���Y�A�������o�ۥե��A���G�i�H�b�W�Y�g�r�I�H\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}
