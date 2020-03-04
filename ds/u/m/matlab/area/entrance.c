// Room: /u/m/matlab/area/entrance.c

inherit ROOM;

void create()
{
	set("short", "���t���s�}�U");
	set("long", @LONG
�o�ئ��s�l�����A�a�ݷ����A�צ~���������H�Ϩu�ܡA�׫e�誺���r
�˻ᦳ�@�f���o�A�u�O�h�����G�]�Q�_���F�A���r���Ǫ��j���_�n���i�e�@
�H�q�L�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"start.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/3.c" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
