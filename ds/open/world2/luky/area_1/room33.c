// Modify with AreaMaker1.0
// Room33.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b�@���H�ϵ}�֪���L�̡C��B���O���j�����A��M��
�@�}���j�L�ӡA�A�Ԥ����F�ӼQ���y������I�I�z�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room23",
		"south": __DIR__"room43",
		"west": __DIR__"room32",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

