inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
滴滴答答的水聲由上而下傳來，一眼望去，可以看到地底難得一
見的的天空，洞的大小大概可以讓一個人通過，由洞旁牆壁的痕跡來
看，這個洞似乎是有人故意開鑿的，可能是為了讓守護遺跡的魔物吸
收月光的能量之用。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "north" : __DIR__"room-13",
        ]));
        set("objects",([
                   __DIR__"../npc/dark_zombie" : 2,
                 ]) );
        set("light",0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}

