// Room: /open/world1/tmr/frost/footway2.c

inherit ROOM;

void create()
{
	set("short", "�̹D");
	set("long", @LONG
�A�����b�@�����ۤs���ӿ��ت��̹D�A�D���W�ͮ�k�k������A����
�ܥX�o���̹D�֦��H�ϸg�L�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"footway",
  "east" : __DIR__"footway3",
]));
	set("current_light", 2);
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
