// Room: /u/a/alickyuen/area/zoo5.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CRoad�ICyberZoo"NOR);
	set("long", @LONG
�Ө�o�̡A�A�P��|�P�򳾻y�᭻�A�Aı�o�o�̪�������ʪ��骺��
�ܤj�����O�C�A�N�Ҧ����·N�X���F�C�@�����h�A�A�|��F��騺��F�C
�ӦV��n�K�i�H�^��ʪ��骺�D���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zoo11",
  "southwest" : __DIR__"zoo4",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
