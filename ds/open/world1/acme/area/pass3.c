// Room: /u/a/acme/area/pass3.c

inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�A�����b�@���d�骺�s���W�A�s���ƬO�T��A���a�ɬO�\���������A
�n��i�樣��o�o���_�СA���F�i�q���ѫ��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"pass4",
  "south" : __DIR__"farm",
  "east" : __DIR__"pass2",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
