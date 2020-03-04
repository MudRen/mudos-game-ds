// Room: /u/m/mulder/area/road10.c

inherit ROOM;

void create()
{
	set("short", "�s���o�� - �V�m�Ҩ��Y");
	set("long", @LONG
�w��A�Ө�V�m�ҡI�A�i�b�o�ضi��V�m�A�Ӵ��ɦۤv����
���A�Ʊ�A�ন�\�a�I�I
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road9",
  "south" : __DIR__"road15",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/master.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
