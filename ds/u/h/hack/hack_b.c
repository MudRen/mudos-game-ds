#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
    set_name(RED"�b��"WHT"�G��"HIY"��g�O"NOR,({"hack board","board"}));
    set("location","/u/h/hack/workroom.c");
    set("board_id", "hack_b");
    set("long","�o�O�@���\�h�����ҲզX�X�Ӫ�����ޯd���O�C\n");
   set("master","hack");
	setup();
    set("capacity",50);
replace_program(BULLETIN_BOARD);
}
