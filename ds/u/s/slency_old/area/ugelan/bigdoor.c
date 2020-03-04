// Room: /u/s/slency/area/ugelan/bigdoor.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"�����f"NOR);
	set("long", 
"�o�̬O���ʨ����̤j�������i�վB�����j�������f�A�A�ݨ�\n""�H�������a�ө��A��y���R���F���x�𮧡A�b�o�̥i�H�M���ݨ���\n""���������ѽ��סA�A���T�Q�Y��i�h�@�@�C\n\n"	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road1",
  "south" : __DIR__"farm5",
]));
	set("light",1);
	set("objects", ([ /* sizeof() == 2 */
 __DIR__"npc/bigguard" : 1,
 __DIR__"npc/guard1" : 4,
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
setup();
	replace_program(ROOM);
}
