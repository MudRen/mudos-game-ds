// Room: /u/a/alickyuen/area/dr30.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�IRestroom");
	set("long", @LONG
�o�جO�@����ͩM�@�h�̪��𮧫ǡA�S�O�������A�ܦh��ͩM�@�h��
�b�𮧮ɶ��ɨӳo�إ𮧤@�U�M�ܤ@�M�F��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"dr27",
]));
set("objects", ([
__DIR__"npc/wnurse.c" : 1,
]));
	set("world", "future");
set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
