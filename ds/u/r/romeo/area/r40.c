// Room: /u/k/king/area/r40.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m�C�P�L");
	set("long", @LONG
�g�L�@�q����������A�b�A���e���@������j���A�W���M�����g�ۡ�
�u�L���Сv�A�ݰ_�ӤQ����ģ���A���\�O�Q�j�������@�A���۲��Y�����
�A�򯫯����𮧡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"41",
  "south" : __DIR__"r34",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
