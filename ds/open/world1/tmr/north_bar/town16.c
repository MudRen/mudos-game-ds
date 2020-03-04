// Room: /open/world1/tmr/north_bar/town16.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���ЫѤl");
	set("long", @LONG
�A�����b�@�B�Ѥl�̡A��ǩЫΪ�����A���O�ѿj����
���C�����|���X�ӧ��̪��p�ĩI�S�ӹL�C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"town14",
  "northwest" : __DIR__"town17",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
