// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�s�a"NOR);
	set("long", @LONG
�����̦��W���s���O�b�o�C�y���A���\�h�ȤH���O���q���~�}�W�Ө�
���C��W���ӧi�ܵP(note)�C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room068",
	    "down" : __DIR__"room106",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

