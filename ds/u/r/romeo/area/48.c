// Room: /u/k/king/area/48.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m������");
	set("long", @LONG
�o�̴N�O���������j���f�F�A������f�@�ѵL�Ϊ��O�q�N��A�w�ͥ�
�����F�X�ӡA�|�P������S�񤧫e��[�������A�ݨӬO���ਫ�^�Y���F�A
�u���w���ݬݤ~���@���͸��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"49",
  "south" : __DIR__"47",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
