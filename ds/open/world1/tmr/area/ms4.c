// Room: /u/t/tmr/area/ms4.c

inherit ROOM;

void create()
{
	set("short", "�D��");
	set("long", @LONG
�A�����b�@���D���W�A������ǹM�ӤF�h��A�@�ǧ��������b�𽮩�
�U���׻Ŵ��A���ʸ��j��U��m�ۤ@�ӡu�^������v�A�����L���H���ΡC
���F��L�h�N�O�s�����A�СA����i��F���l�̡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"vroad1",
  "east" : __DIR__"ms2",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
