// Room: /u/k/king/area/31.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m�C�P�L");
	set("long", @LONG
�o�̴N�O�԰�ӳ��ĤG�h�A�ﭱ�j�Ӫ��N�O�@�}�����A�A���W������
���D���H�g�����a�F�A��X�B���O�M�C�A�n���Ԫ��~�赲���A�A���ߤ��S
���F�x�Ī��Q�k�A�٬O�֨��a�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r32",
  "down" : __DIR__"r30",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
