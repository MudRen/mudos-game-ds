// Room: /open/world1/tmr/ghost-forest/forest7.c

inherit ROOM;

void create()
{
	set("short", "�ծ|");
	set("long", @LONG
�A�����b�L���@���ծ|�A�A�uı�o�p�|��Ǫ����F�L�ͮ�A��y�L
���R��ۤ@���{�e��ä���A�O�H���H�ӷX�A�u�Q���I�����A���@�����}
�o�ذ��a��C
LONG
	);
	set("world", "past");
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"forest5",
  "northwest" : __DIR__"forest9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
