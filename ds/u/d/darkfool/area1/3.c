// Room: /u/d/darkfool/area1/3.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�o�̥��Z���������H���b�W���D�`���ΪA�A�A�a�ۿE�઺�����C
�Y��F��}�U�����T�n����D�F�A�i�H�P������o�����Ыت̭�
�ҧ�J�����Ѽ��ۡC�_�䦳�@����y�p�ΡA�F�褣���B�K�O��W���s
���C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"4",
  "north" : __DIR__"5",
  "west" : __DIR__"2",
]));

	setup();
	replace_program(ROOM);
}
