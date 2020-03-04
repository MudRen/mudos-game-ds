inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
在空曠的走道中，你不時覺得有人在監視你，但卻又無法確信是
否真的有人在監視你，東邊的房間中傳來一些細微的聲響，似乎有人
在那邊活動的樣子，你不妨去看一下。
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "east" : __DIR__"room-11",
                  "north" : __DIR__"room-14",
                  "south" : __DIR__"room-06",
        ]));
        set("light",0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}

