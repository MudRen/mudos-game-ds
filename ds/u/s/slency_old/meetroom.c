// Room: /u/s/slency/area/meetroom.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIC"�վB����"HIW"�{�ɷ|ĳ��"NOR);
	set("long","�o�̬O�@����j���|ĳ�U, ���C�Q������, �ݨӬO�Ův�}�{�ɷ|������, \n""���W��"YEL"�@��"NOR"�٦b�_��...�C\n");
	set("exits", ([ /* sizeof() == 2 */
  "test" : __DIR__"area/ugelan/farm1",
  "out" : __DIR__"workroom",
]));
	set("no_clean_up", 1);
	set("light",1);
	setup();
	replace_program(ROOM);
}
