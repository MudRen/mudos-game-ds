// Room: /u/a/alickyuen/area/zoo3.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CRoad�ICyberZoo"NOR);
	set("long", @LONG
�o�䪺�O������c���ʪ��A���\�B�Ѫ굥�A���߿W�O�S����l�Cť�F
�޲z�������ܫ�~���D��l�]�����L�ʪ����M�ӳQ�L�̹j���F�C����N
�i�H�h��ө��Τ����]�����a��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zoo7",
  "east" : __DIR__"zoo",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
