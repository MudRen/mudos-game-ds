// Room: /u/k/kenshin/sha-zin-gu/room21.c

inherit ROOM;

void create()
{
	set("short", "[1;33m�p���x[0m�x�f[0m");
	set("long", @LONG
�ש�Ө�p���x�F�A�ݨ쨺���Y���x�q�A�߸̤]���T���Y�ԨǡA��
�`�������e�]���_�F���֡C���F�ݨ�«����H���A�]�ݨ�x�̪����q��
�b���@�Ƿ�a���~�����Ұg�A�߸̷Q�@�Q�A�o�ǤH���u�O�g�H�A���L�e
�H�ҥܹ�i�H�䦳�B���i�H��L�A���ӴN�O�o�ӷN��a�C
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"room20",
  "north" : __DIR__"room22",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
