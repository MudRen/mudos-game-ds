#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
    set_name("�b�ȯd���O",({"board"}));
    set("location","/u/h/hack/workroom.c");
    set("board_id", "hack_b");
    set("long","�o�O�@�����s�������d���O�C\n");
set("master","hack");
	setup();
    set("capacity",50);
replace_program(BULLETIN_BOARD);
}
