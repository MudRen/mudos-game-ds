/**
 * Shadow's area [�򩳥@�� - �����ʨc - a9]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIR"�����ʨc"NOR);
	set("long",@LONG
�ѵM���۾��A���O���H�u���w������C�����b���B���`�a���R�A
���G�S������~�O�i�H�z�Z�o��...�C�w�w�a���y�P�ʨc�����˲@��
�f�աA���G���ة_�Ǫ��O�q����۳o�����ʨc�C
LONG
	);
	set("light", 0);
	set("no_clean_up", 0);
	set("exits",([
		"east" : __DIR__"a10",
		"north" : __DIR__"a11",
		"southwest" : __DIR__"a8",
	]));

	setup();
	replace_program(ROOM);
}

