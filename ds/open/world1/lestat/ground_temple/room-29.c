inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
詭異的古代文字依然刻滿在四周的牆壁上，所散發的光芒卻由清
綠色轉成暗紅色，還帶著陣陣的血腥味，原來周圍的牆上到處是一灘
灘的血跡，看來這裡曾經發生很激烈的戰鬥跟殺戮。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "southeast" : __DIR__"room-26",
        ]));
        set("objects",([
                   __DIR__"../npc/yuan" : 1,
                 ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        setup();
}


