// Room60.c

inherit ROOM;

void create()
{
        set("short","【法旋堂】");
        set("long", @LONG
來到這裡彷彿置身人間仙境，一切充滿了祥和寧靜還
不時的可以看到許多珍禽異獸在這裡嬉鬧在你東邊有個站
在龍上的白衣人正在對著三具石像沉思似乎正在領悟著什
麼。
LONG
        );
        set("exits", ([
                "west": __DIR__"room25",
        ]));
        set("light",1);
        set("objects",([
                "/open/world1/npc/goldman2" : 1,
		__DIR__"item/goldman2" : 1,
        ]));
set("no_goto",1);
        setup();
}
