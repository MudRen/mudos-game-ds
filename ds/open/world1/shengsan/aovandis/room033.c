// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�谼����"NOR);
	set("long", @LONG
�A�b���Z�}�����谼�����̡A��ꪺ����N�b�A�����ǡA����O�Ѥ�
�����j���[���ҫسy�Ӧ��A�㦳�۷����m��O�A�~����G���@�ǳQ���L
������A�o�����F�o�̦��G���g�o�͹L�Ĭ�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room026",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/gateguard" : 2,
	]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}