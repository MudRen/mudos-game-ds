//3012
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CRoad�ICyberZoo"NOR);
	set("long", @LONG
����o�ˡA�A�P�즳�@�I�֤F�A���n�b�F�_�����@�Ӥp�p������ѹC
�H�𮧤@�U�C�P���P�ɡA�Ať��b��_�����@�}�}��l���q�s�n�A�ݨӨ�
�����ӬO��m��l���a��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"zoo5",
  "south" : __DIR__"zoo2",
  "northwest" : __DIR__"zoo6",
]));
set("objects", ([
__DIR__"npc/zooer.c" :1,
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
