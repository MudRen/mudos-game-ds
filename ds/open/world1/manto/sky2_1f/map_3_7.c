// Room: /open/world1/manto/sky2_1f/map_3_7.c

inherit ROOM;

void create()
{
	set("short", "�r��");
	set("long", @LONG

LONG
	);
	set("light", 1);
	set("map_long", 1);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 3 */
  "up" : "/open/world1/manto/sky2_2f/map_5_8.c",
  "east" : __DIR__"map_3_9",
  "southwest" : __DIR__"map_5_5",
]));

	setup();
        set("stroom", 1);
}
int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me))
        {
        if(CLUB_D->check_member("sky",getuid(me)) < 3 && CLUB_D->check_member("ming",getuid(me)) < 4)
                return notify_fail("�A�Q�����a���F�^�ӡC\n");
        }
        return ::valid_leave(me, dir);
}
