// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���v�u�|����"NOR);
	set("long", @LONG
�o�̬O���Ū��v�m�ߧޯ઺�ж��A���쪪�v�ɮv�b�o�оɾǥͪ��v��
��C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room095",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

