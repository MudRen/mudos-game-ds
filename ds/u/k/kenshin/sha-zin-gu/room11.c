// Room: /u/k/kenshin/sha-zin-gu/room11.c

inherit ROOM;

void create()
{
	set("short", "[1;36m�Z�Ǥ���[0m");
	set("long", @LONG
�o�O�Q�������}�𪺤H�������g�����A�u�n�A���e���A�N��@��
�Z�̱J�@�C���訫���F�v�騦���A���w�y�ƥ��A���z�C
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room8",
  "north" : __DIR__"room24",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
