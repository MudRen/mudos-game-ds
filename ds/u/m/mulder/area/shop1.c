// Room: /u/m/mulder/area/shop1.c

inherit ROOM;

void create()
{
	set("short", "�s���o�� - ��D");
	set("long", @LONG
�b�o�اA�ݨ��@�y�]�ƫܥ��i���j�ӡA��ӳo�O�s���o����
ĵ��j�ӡD�Ǥ��o�o��ªZ�I�I
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road6",
  "south" : __DIR__"road11",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
