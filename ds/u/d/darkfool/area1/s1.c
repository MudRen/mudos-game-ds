// Room: /u/d/darkfool/area1/s1.c

inherit ROOM;

void create()
{
	set("short", "�n��v�ϵ�D");
	set("long", @LONG
�A���J�F��n����v�ϡA�t���Τ@�ӭӤ��M���Ǧa�ƦC�ۦV�n�X
���L�h�A�X�ө~���P�A�����ӹL�A�n�_�a���q�ۧA�o�~�Ӫ����ͤH�A
�ڻ��p��W�ߤ@����ʹN�O��b�o�@�Ϫ��Y�B�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"s2",
  "north" : __DIR__"c1",
]));

	setup();
	replace_program(ROOM);
}
