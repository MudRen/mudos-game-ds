// Room: /open/world1/acme/area/senwu2.c

inherit ROOM;

void create()
{
	set("short", "���g�p�|");
	set("long", @LONG
�A�����b���g�p�|�W�A�|�P�������¡A���oı�o�Q������A����
�𤣪��q��ǨӡA�����o�_�X�@�����C���U�|��A�J�����u�����⪺
�F�g�A�õL�S�O���B�A�O�Hı�o�Y�D�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"senwu3",
  "west" : __DIR__"senwu1",
]));
	set("world", "past");
    set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
