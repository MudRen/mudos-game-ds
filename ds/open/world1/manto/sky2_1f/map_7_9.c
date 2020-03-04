// Room: /open/world1/manto/sky2_1f/map_7_9.c

inherit ROOM;

void create()
{
	set("short", "�s��Ѧa");
	set("long", @LONG

LONG
	);
	set("current_light", 2);
	set("light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_5_9",
  "east" : __DIR__"map_7_11",
]));
        set("objects",([
    __DIR__"obj/heaven_box" :1,
]));

	setup();
      call_other( "/open/world1/manto/sky2_1f/board/sky_newbie_b", "???" );
        set("stroom", 1);
}
int valid_leave(object me, string dir)
{
        if( dir=="north" && !wizardp(me))
        {
        if(CLUB_D->check_member("sky",getuid(me)) < 2 && CLUB_D->check_member("ming",getuid(me)) < 3)
                return notify_fail("�A�Q�����a���F�^�ӡC\n");
        }
        return ::valid_leave(me, dir);
}
