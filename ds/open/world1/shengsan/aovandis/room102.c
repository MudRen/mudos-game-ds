// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ův�u�|����"NOR);
	set("long", @LONG
�o�̬O���ŧŮv�m�ߧޯ઺�ж��A����Ův�ɮv�b�o�оɾǥͥi�Ȫ�
�Ův�ޯ�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room085",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

