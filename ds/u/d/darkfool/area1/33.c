// Room: /u/d/darkfool/area1/33.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�A���b�o�̬�M�@�}�D���j�ӡA���A���ؤ��H�ӷX���Pı�A�A��
�F��|�B�A���F�H����֡B�Фl�]����֤��~�A�n���S����S�O���B
�A�γ\�O�A�ӱӷP�F�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"34",
  "west" : __DIR__"32",
]));

	setup();
	replace_program(ROOM);
}
