// Room: /d/xiangyang/juyihuayuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "花園");
	set("long", @LONG
這是聚義館的大花園。園內種著各種各樣的花草，清風吹
來，你能聞到股股花香。園內東西兩側各有一排廂房，北面是
一湖池水，水上架著走廊，直通西大街。南面是館內廚房，東
南方向有一間物品房。
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"      : __DIR__"juyifemale",
		"west"      : __DIR__"juyimale",
		"south"     : __DIR__"juyichufang",
		"north"     : __DIR__"juyilang",
		"southeast" : __DIR__"juyiwupin",
	]));
	set("objects", ([
		__DIR__"npc/guofu" : 1,
	]));
	set("coor/x", -530);
	set("coor/y", -503);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (me->query("gender") != "男性" && dir == "west") 
		return notify_fail("男女有別，請到對面住！\n");

	if (me->query("gender") != "女性" && dir == "east") 
		return notify_fail("男女有別，請到對面住！\n");

	return ::valid_leave(me, dir);
}