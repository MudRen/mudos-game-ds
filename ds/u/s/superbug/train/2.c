// Room: /u/s/superbug/train/2.c

inherit ROOM;

void create()
{
	set("short", "�Ԩ���");
	set("long", @LONG
�o�O�@�����ȫȵ��ݤ������a��A�\��۳\�h�i�����ȡA�i�O�o����
�����S���X�ӤH�A�u���X�Ӭy���~���b�Ȥl�W��ı�A�b�G�i��W���G�K��
�Y�ǪF��A���٦��@�x�c����C
LONG
	);
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"1.c",
  "enter" : __DIR__"4.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
