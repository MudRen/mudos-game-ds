// Room: /u/k/king/area/r34.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m�C�P�L");
	set("long", @LONG
�o�̬O�|�P���ﺡ�F�Z�\���D�A�u�d�U�@���p�p���q�D�A�b�A���Y��
�����W�観�@�����B�A�W���g�ۡG�u�Z�\���a�v�A��ӳo�̬O�������Ҥ�
�o����´���@�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r32",
  "north" : __DIR__"r40",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tammi" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
