#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name( HIM"�t�O"NOR ,({ "Legendary pillar", "pillar","board" }));
    set("location","/open/world1/meetroom_west.c");
    set("board_id", "past_west_b");
	set("long",@LONG
�o�Ӥj�۸O�N���@�ڳ��ѥߦa���ɼ٤@��, �Q���������[, ���F
�~�[��H���~, �۸O���W�]��F�\�h�ϧ�, �����D�H�x�ۤ���F
��? ���O����ޤH�`�N���O, �ϧ��_�ؤ�������W�F�K�K�³ª�
��r.
LONG
	);
	setup();
	set("capacity",150);
	set("master",({ "baal","uchimaha" }));
}
