/**
 * Shadow's area [�򩳥@�� - �򩳺ʨc - a9]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIR"�򩳺ʨc"NOR);
	set("long",@LONG
�ѵM���۾��A���O���H�u���w������C�����b���B���`�a���R�A
���G�S������~�O�i�H�z�Z�o��..�C�o���\�]�ۤ@�i��l�H�ΤT�i��
�l�A��W���\�۩|���Χ����s�A�����A�ݨ����O�޲z���򩳺ʨc����
�u�Ҧ��C
LONG
	);
	set("light", 0);
	set("no_clean_up", 0);
	set("exits",([
		"north" : __DIR__"a12",
		"west" : __DIR__"a9",
	]));

	setup();
	replace_program(ROOM);
}

