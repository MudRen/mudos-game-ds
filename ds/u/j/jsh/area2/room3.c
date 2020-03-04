inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
你愈往這山洞裡面走，就愈聽的到有人在輕輕戲語的聲音，也有一些
雜聲，應該是蟲獸的聲音吧，在西邊的路上隱隱的可以看到燭光，你環視
著這附近，陰暗潮濕，這裡常會有蛇出沒。
裡面還有一段路。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room4",
  "northeast" : __DIR__"room2",
]));
        set("objects", ([ /* sizeof() == 1 */
          __DIR__"snake" : 2,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();

}

