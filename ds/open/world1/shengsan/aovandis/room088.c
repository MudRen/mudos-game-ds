// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�W�h���D"NOR);
	set("long", @LONG
�A���b�@�ƱƩ��_�ӤW���۶����W�A�۶��W�^�ۦU�ج��R���[���A��
�ƥX�����˼˦����H��i�ҫ�C�q�o���訫�O�k�v�u�|�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room093",
	    "west" : __DIR__"room092",
	    "south": __DIR__"room089",
	    "north": __DIR__"room082",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}