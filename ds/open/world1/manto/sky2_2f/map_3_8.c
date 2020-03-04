// Room: /open/world1/manto/sky2_2f/map_3_8.c

inherit ROOM;

void create()
{
	set("short", "��D��");
	set("long", @LONG

LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"map_1_8",
  "east" : __DIR__"map_3_10",
  "west" : __DIR__"map_3_6",
  "south" : __DIR__"map_5_8",
]));
        set("objects",([
    __DIR__"obj/heaven_box" :1,
]));

	setup();
      call_other( "/open/world1/manto/sky2_1f/board/sky_decision_b", "???" );
        set("stroom", 1);
}
int valid_leave(object me, string dir)
{
        if( dir=="north" && !wizardp(me))
        {
        if(CLUB_D->check_member("sky",getuid(me)) < 6 && CLUB_D->check_member("ming",getuid(me)) < 7)
                return notify_fail("�A�Q�����a���F�^�ӡC\n");
        }
        return ::valid_leave(me, dir);
}
