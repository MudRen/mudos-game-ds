inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
這個山洞真是無比的巨大，而且洞壁都非常的平整，不像是天然的洞
穴，讓你聯想到剛剛在洞外看到的「古墓」二字，一定是有人建造的，想
到這，就讓你興起一股莫名的興奮，想要一探洞內是否還有人。
裡面還有一段路。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"room3",
  "east" : __DIR__"room1",
]));
        set("objects", ([ /* sizeof() == 1 */
          __DIR__"statue" : 1,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();

}


