/**
 * Shadow's area [�򩳥@�� - �򩳺ʨc - a11]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIR"�򩳺ʨc"NOR);
	set("long",@LONG
�ѵM���۾��A���O���H�u���w������C�����b���B���`�a���R�A
���G�S������~�O�i�H�z�Z�o��..�C���ª��ʨc���H�B�i���ʸT�}��
�Ϊ��D��A�U�ة_�ΩǪ����}��ݱo�A�x�ԤߴH�A�ߤ��@�}���w�C
LONG
	);
	set("light", 0);
	set("no_clean_up", 0);
	set("exits",([
		"east" : __DIR__"a12",
		"south" : __DIR__"a9",
	]));

	setup();
	replace_program(ROOM);
}

