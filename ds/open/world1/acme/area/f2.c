// Room: /open/world1/acme/area/f2.c

inherit ROOM;

void create()
{
	set("short", "���L");
	set("long", @LONG
�X�������A�q���j�@�K���Z�����g�����t���L���A�L���R�췥�I
�A�|�P���O���j�����A�N����F�t�@�@�ɯ�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"f3",
  "south" : __DIR__"f1",
]));
     set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
