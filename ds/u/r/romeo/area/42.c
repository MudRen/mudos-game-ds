// Room: /u/k/king/area/42.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m�C�P�L");
	set("long", @LONG
�o�̬O�Q�j���⤧�@����d�q����ҡA�u���@�i�ɡA�@�i�ֳQ�A�N
���򳣨S���F�A�ڻ��L���S���@�w���ɶ��^�ӡA�L�n�����H�٨S���@�ӥi�H��
�R���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r33",
  "east" : __DIR__"43",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/swordgod" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
