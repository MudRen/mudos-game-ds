// Room: /u/a/alickyuen/area/zoo14.c
//updated by alickyuen 9/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CSecret�ICyberZoo"NOR);
	set("long", @LONG
�b�o�̯��O��b�Ӱ��򥻬ݤ��M���F��n�_�O�A�߱��J��A�Ʊ�ɦ�
�X�h�C���ۨ��ۡA�A���T���Ǥ߷W�F�C�A����ı�i�D�A�A�M��X���O�{�b
�A���Ӱ����ơC
LONG
	);
	set("exits", ([ /* sizeof() == 8 */
  "northwest" : __DIR__"zoo13",
"southwest":__DIR__"zoo13",
"north":__DIR__"zoo13",
"south":__DIR__"zoo13",
"southeast":__DIR__"zoo13",
"northeast":__DIR__"zoo13",
"east":__DIR__"zoo15",
"west":__DIR__"zoo13",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
