// Room: /u/m/matlab/area/start.c

inherit ROOM;

void create()
{
	set("short", "�_����");
	set("long", @LONG
���e�ѩ���u�Q���L�z�A�b�n�̤��w������اA�u��̵}�a��{�X
�o���G�O�@�y�Q������������A�|�P���C�ۼƤQ�L���j�����F�۹��A�b
���v�\�ʤU����o���˥i�ȡA�b���a��{�����Ů������ǨӨ��������n�A
�A���إu�Q�������}�o�ءC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r1.c",
  "out" : __DIR__"entrance.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/2.c" : 4,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
