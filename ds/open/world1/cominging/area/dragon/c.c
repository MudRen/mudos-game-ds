#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"狂龍幫"HIM"－"HIY"神龍堂"NOR);
	set("long", @LONG
    這�堿O狂龍四堂之一 －【神龍堂】
本堂的主要責任，就是去幫助低等級的玩家打裝備(EQ)。
而本堂亦常陪同幫主去打一些高級的裝備(EQ)的。
本幫幫眾眾多，所以打裝備(EQ)也是非常重要的。
你看到堂中放有許多裝備，除此之外，沒什麼特別之處。
LONG
	);
	set("exits",([
  "southeast" : __DIR__"dragon.c",
]));
	set("item_desc",([
]));
	set("objects", ([ __DIR__"item/weapon_shelf" : 1,
                          __DIR__"item/equip_shelf" : 1,
                          __DIR__"item/item_shelf" : 1, ]));
	set("light",1);
	set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
	setup();
}
