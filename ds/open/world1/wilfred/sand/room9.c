// Room: /open/world1/wilfred/sand/room9.c

inherit ROOM;

void create()
{
	set("short", "���F��f");
	set("long", @LONG
�o�O�@�ӤH�ϵ}�֪��p��A�~���i�ण�W�L�G�Q�H�A����y�����
�F�D�ζ��F�������A��W���������i�ݨ��ȤH�ΰӶ��b�����y�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room10",
  "north" : __DIR__"room8",
]));
	set("outdoors", "land");
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
