#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
	set_name("�ȫȯd���O",({"board"}));
	set("location","/open/world2/lichi_town_2/map_5_26.c");
	set("board_id", "now_malo_b");
	set("long",@LONG
�o�O�@�ӥ|�ؼe���j�ªO�A�W���٦��X�������A���ȫȥi�H�b�W���g
�ǯd���P��ĳ�C
LONG);
	setup();
  	set("capacity",50);
  	replace_program(BULLETIN_BOARD);
}
