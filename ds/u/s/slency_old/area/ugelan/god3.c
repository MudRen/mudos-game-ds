// Room: /u/s/slency/area/ugelan/god3.c

inherit ROOM;

void create()
{
	set("short", "���Y");
	set("long", @LONG
�A�{�b��b�иt���а���Ъ٪����Y�W, ���Y��غ��F���, �@
���Y�Y�V�a�V�Aŧ�F�L��, �Ѧ��A���e���i�H��F�@�ǯ������ж�, ��
���a�A�i�H�ݨ��а��誺�C���W���@���Ӷ�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"god9",
  "out" : __DIR__"god2",
  "east" : __DIR__"god4",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
