// Room: /u/t/truewind/Minetown/area/minetown5.c

inherit ROOM;

void create()
{
	set("short", "�q���u�d�e");
	set("long", @LONG
�o�̬O�q�������@���Ŧa�C�n��N�O�q�����q�u�~���u�d�F�C
���@���ۤl���������n��q�L�h�A�Ӫ��񰣤F�X�ӥ��b���̪��q�u�A
�S������S�O���a��A���L�a�W���ө_�Ǫ��p���Y(rock)���{�{�o�G
�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("outdoors","land");
	set("item_desc", ([ /* sizeof() == 1 */
  "rock" : "�_�Ǫ������Y�A�W�Y�g���H���Ծ��������D����...�H
",
]));
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"minetown6",
  "west" : __DIR__"minetown8",
  "east" : __DIR__"minetown4",
  "south" : __DIR__"workerroom1",
]));

	setup();
	replace_program(ROOM);
}
