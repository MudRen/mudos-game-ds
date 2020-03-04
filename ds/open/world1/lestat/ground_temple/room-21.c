inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
滿地的血跡以及堆積如山的骨骸，迎面而來的腥羶味，構成了一
幅怵目驚心的景象，地上有不少黃黑白三色的獸毛，可能是某種野獸
所掉落的，這裡大概是牠的獸窩吧。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "east" : __DIR__"room-22",
        ]));
        set("objects",([
                   __DIR__"../npc/tiger_man" : 2,
                 ]) );
        set("light",0);
        set("no_clean_up", 0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        setup();
}

