// Room: /future/area/hotel.c

inherit ROOM;
void create()
{
	set("short", "礦區酒館");
	set("long", @LONG
這是一間頗大的酒館，也是這區唯一的酒館，是這附近工人在一天辛
苦的工作之後，都會來這小酌一番，你不時可聽到隔壁桌傳來喧嘩吵鬧的
划酒聲，你可看到酒館老板正親切地和客人聊天、喝酒。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	  "east" : __DIR__"digging_road1",
        "up" : __DIR__"hotel_2f",
	]));
               set("objects", ([ /* sizeof() == 1 */
                    __DIR__"npc/hotelrobot" : 1,
                      __DIR__"npc/li-r-ka" : 1,
               ]));
	set("world", "future");
	set("valid_startroom", 1);
	set("no_clean_up", 0);
	set("no_magic", 1);
	set("light", 1);
	set("no_kill", 1);

	setup();
        call_other("/obj/board/tmr_future_b", "???");
}
