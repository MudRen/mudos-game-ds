// Room: /u/a/acme/area/corridor.c

inherit ROOM;

void create()
{
	set("short", "���Y");
     set("light",1);
	set("long", @LONG
�o�̬O���Z�Ф������Y�A�u�ۨ��Y�\�W�F�@�Ƭ֮�A�W�Y��ص۩_��
����A�����ڡA�O�Aı�o���M��n�C�F��ǨӤF����n�A��ӬO���m�Z
�j�U�A����h�O�øg�աA���n�i�q���j�U�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"portal",
  "west" : __DIR__"library",
  "south" : __DIR__"parlor",
  "east" : __DIR__"hall",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
