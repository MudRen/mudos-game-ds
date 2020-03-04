inherit ROOM;

void create()
{
        set("short", "固山寨小土丘");
        set("long", @LONG
這裡是一個小土丘，被駐紮在固山寨裡的官兵們拿來當臨時
的垃圾掩埋地，當然也是有機肥料的集中地點。旁邊架著幾個木
板搭建的簡易聽雨軒。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"camp006",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

