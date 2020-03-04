// Room: /u/k/king/area/41.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m�C�P�L");
	set("long", @LONG
�o�̴N�O���������D��Ū�d�g���m�\���F�A�ݨ�k���䦳�@�D��L�A
�����䪺�@���_�𦳤@�b�O�Q�B�ʡA�t�@�b�o�Q���ƤF�A�����D�O�Q����
���ƪ��Z�\�������A�n�O���b�H���W�A�u�����F���U�Ѫ����F�C 
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r40",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bulada" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
