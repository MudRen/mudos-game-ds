// Room: /u/f/fanny/area/forest/forest1.c

inherit ROOM;

void create()
{
	set("short", "�Q��L");
	set("long", @LONG
�o�̬O�@���Z�K���Q��L�A���R���o���G�t�õ۱����A�ݦ��;�
�k�k����L�A���ݤ������@�����ʤ������~�A�ݰ_�ӯu���@�ػ���
�X���޲��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"forest2.c",
]));

	setup();
	replace_program(ROOM);
}
