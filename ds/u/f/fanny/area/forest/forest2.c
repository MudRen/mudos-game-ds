// Room: /u/f/fanny/area/forest/forest2.c

inherit ROOM;

void create()
{
	set("short", "�Q��L");
	set("long", @LONG
��`�J�˪L�A�ھڧA�����h�~���g��A�o��ݰ_�Ө��ٯu�O�A�Q
������@�^�ơA�̵}�i�H�Pı�X�����±�����A���L�o�a��o�٦��t
�~�@�Ѳ��W�����O�C���n���O�@�����Ҹg�~�֤��㨫�X���s�|�A�_
��ݼˤl�O�@�����~�X�����p�|�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"forest5.c",
  "west" : __DIR__"forest1.c",
  "north" : __DIR__"forest3.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
