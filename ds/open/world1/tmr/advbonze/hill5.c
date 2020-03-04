// Room: /open/world1/tmr/advbonze/hill5.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�p-�W�s�p�|");
	set("long", @LONG
�A�����b�q���ⶳ�p�����p�|�A�ѩ�D���U���A���ɱo�������L
�����H�A�H�K�����Ӽ�����Ǫ���L�C�o�������_����V���G�u��j
������b�s�y�A�A�n�q���ⶳ�p���A�o�A�����|�F�a�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hill7",
  "southwest" : __DIR__"hill4",
]));

	setup();
	replace_program(ROOM);
}
