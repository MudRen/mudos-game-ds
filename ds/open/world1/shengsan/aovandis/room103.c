// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�p����"NOR);
	set("long", @LONG
�A�o�{�@�y�p�����b�o�̡A���O�o�䤣�X����i�H�i�h����k�A�]�\
�o�̬O���L�i�X�@�ɪ��X�J�f�a�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"room083",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

