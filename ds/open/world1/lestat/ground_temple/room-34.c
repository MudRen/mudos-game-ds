inherit ROOM;

void create()
{
        set( "short", "地底洞穴") ;
        set( "long", @LONG
陰冷的通道中，不時傳來的憂怨嘆息聲，終於在前方看到了一點
光亮，那奇異的亮光彷彿在召喚著你，讓你想不顧一切地衝過去，但
是旁邊的岩壁上有一些字跡，還是先看一下比較好。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "north" : __DIR__"room-36",
                  "south" : __DIR__"room-33",
        ]));
        set("objects",([
                   __DIR__"../npc/beauty_ghost" : 1,
                 ]) );
        set("light",0);
        set("item_desc", ([ /* sizeof() == 1 */
        "字跡" : "前方乃是五行迷魂陣，進去後時空交錯變換，想進入者，請三思！\n",
        ]) );
        set("no_clean_up", 0);
        setup();
}

