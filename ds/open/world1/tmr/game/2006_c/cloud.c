// Room: /u/t/tmr/game/2006_c/cloud.c

inherit ROOM;

void create()
{
	set("short", "�b�Ť�");
	set("long", @LONG
�A���b�b�Ť��A�|�g���O���ӭ��h�������W���G�ѤH�A�I�۬���
���j�U�l�A�����a�������ۡC
LONG
	);
	set("sort", "�b�Ť�");
	set("light", "1");
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "down" : "/open/world1/tmr/area/hotel",
]));
	set("no_clean_up", 0);
	setup();
}
int valid_leave(object me, string dir)
{
      ::valid_leave();
        if( !userp(me)) return 0;
        return ::valid_leave(me,dir);
}

