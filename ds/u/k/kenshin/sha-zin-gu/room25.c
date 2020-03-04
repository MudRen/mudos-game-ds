// Room: /u/k/kenshin/sha-zin-gu/room25.c

inherit ROOM;

void create()
{
	set("short", "�Z�Ǥ��a�w�j��");
	set("long", @LONG
�ש�Ө�F�o�A�Ө�F�o���ӴN�ਣ�W�e�Z�L�֫L����M�F�a�A
���F�Ө��L�A�]�n�n�n��Ф@�f�o�̧̤l����O�C
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room26",
  "south" : __DIR__"room24",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
