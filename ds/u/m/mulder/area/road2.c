// Room: /u/m/mulder/area/road2.c

inherit ROOM;

void create()
{
	set("short", "�s���o��-�s���j�D");
	set("long", @LONG
�g�L�ȩ��j�󤧫�A�A�N����F�s���j�D�D�A�ݨ��ܦh���P
���ɪź}�y�̦b�o�ظg�L�άO�b�ͤѥ���߱o�D
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road1",
  "north" : __DIR__"road3",
]));
	set("shot", "�s���o�� - �s���j��");
set("outdoors", "road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
