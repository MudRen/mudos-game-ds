// Room: /open/world1/dragoncity/walln1.c

inherit ROOM;

void create()
{
	set("short", "�F���Y");
	set("long", @LONG
�o�̬O�Y�s�����F���Y�C�@�Ǥ֫ӭx�l�̧L���b���Y���ޡA
�@�Ӥ��N���b�o��t�d�����U�ئu�����ơA�@�Ǥ}�b�⥿���}
�f�b��n�۫��U�����R�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "down" : __DIR__"walle1",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 2);
	set("objects", ([
		__DIR__"npc/guard2" : 1,
		]));
	setup();
	replace_program(ROOM);
}
