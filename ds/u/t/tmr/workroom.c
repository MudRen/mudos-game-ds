// Room: /u/t/tmr/workroom.c

inherit ROOM;

void create()
{
	set("short", "�_�a�j��");
	set("long", @LONG
�o�O�_�a�j���A���n�O�ɿ������A�p����ۻ����A�ˤ���i�h.
�_�a�ݬݡA�Ϊ̥i�H�h�ɿ��ݬݡu�¤Ѵ�v�o�ӦW�ӡA���F�i��@
�Ӥp��C
LONG
	);
	set("valid_startroom", "1");
	set("outdoors", "lands");
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 4 */
  "past" : "/open/world1/tmr/area/hotel",
  "enter" : __DIR__"room/square",
  "wiz" : "/d/wiz/hall1",
  "future" : "/open/world3/tmr/basic/hotel",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
