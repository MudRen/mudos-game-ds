// Room: /u/k/king/area/r36.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m�C�P�L");
	set("long", @LONG
�o�̬O�@���p�T�ΡA�򥭱`�ݨ쪺�T�ΨS���򤣤@�ˡA���O�|�b�o��
�N�O������@�I�����`�A�ݬݤW���n���}�@�Ӭ}�A�A�i�H�յ۪����ݡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"r32",
  "up" : __DIR__"46",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
