// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���]�G��"NOR);
	set("long", @LONG
���Ū��ж��N�O�o�̤F�A�A�ݨ�o�̪����C�ή�^�Nı�o�h�ҫ״
�F�@�b�C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "north": __DIR__"room105",
            "down" : __DIR__"room079",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

