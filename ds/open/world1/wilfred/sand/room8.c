// Room: /open/world1/wilfred/sand/room8.c

inherit ROOM;

void create()
{
	set("short", "�����p��");
	set("long", @LONG
�q���B�h�A���䪺�C�������F���A���n�����B�h�O���F�D�W��
�@���p��ж��F��A�n�O�A�Ȧ�֤F�A�����i�H�h��W�����C�Ӧ�
�B����訫�A�h�O�������W���Y�s���A�n���ѤU�Ĥ@�l��-�֫ӭx�C
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/npc4" : 4,
]));
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room9",
  "east" : __DIR__"room4",
  "westup" : __DIR__"room34",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
