// Room: /u/t/truewind/Minetown/area/plane-room.c

inherit ROOM;

void create()
{
	set("short", "飄浮車停靠坪");
	set("long", @LONG
四周用巨大的鐵絲網圍起來，這裡是礦村的漂浮車停靠坪。也是
重要的物資轉運點，採得的珍貴礦物跟研究用的生物都從這裡轉運回
星聯總部。幾臺運輸型漂浮車正在車坪中停靠著。幾名工人正忙碌的
把貨物搬上搬下。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"minetown7",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("current_light", 1);
        set("objects", ([ 
        __DIR__"obj/obj1.c" :1 ,
]));
	setup();
	replace_program(ROOM);
}
