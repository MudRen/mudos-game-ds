#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name( HIW"�F��O�ƿ�"NOR ,({ "record board", "board" }));
	set("location","/open/world1/meetroom_east.c");
	set("board_id", "past_east_b");
	set("long",@LONG
�@���Υ��m���Ȱ������O�ƿ��A��b�o�̪���W�A���l�O���}��
�A���䦳�X���m��]���A�i�H��(post)�Ӽg�r�O���b�W���A�]�i
�H�ξ����(discard)�����C
LONG
	);
	setup();
	set("capacity",80);
}
