// Room: /u/s/superbug/train/a-23.c

inherit ROOM;

void create()
{
	set("short", "�ө�");
	set("long", @LONG
�o�̬O�h���ϰߤ@���@�������³f�����A����ﺡ�F��n�p�s���f�~�A�p
�G�A������f�~�n�檺�ܡA���i�H����o�̨ӥX��A�h���Ϥj�������f�~���O
�b�o�̥X�⪺�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"a-7.c",
]));
set("objects", ([
__DIR__"npc/seller2.c" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
