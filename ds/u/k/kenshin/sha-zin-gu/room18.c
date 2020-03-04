// Room: /u/k/kenshin/sha-zin-gu/room18.c

inherit ROOM;

void create()
{
	set("short", "[33m�E�s�ȴ̤G��[0m");
	set("long", @LONG
�o�̬O���H��ѽͤߪ��Ҧb�A�A�i�H�a�A���n�ͩξԤͨӨ�o�A
�}�����͡A�Ϊ̥i�Q�ή��䦳���H�ѡA�M�Ԥ@�f�A�i���A�P�L�H����
�Y��n���w�C
LONG
	);
	set("no_goto_cmd", 1);
	set("room_type", "hotel");
	set("no_steal", 1);
	set("no_fight", 1);
	set("no_exert", 1);
	set("no_kill", 1);
	set("current_light", 3);
	set("light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"room17",
]));
	set("valid_startroom", 1);
	set("no_cast", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
