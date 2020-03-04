
inherit ROOM;

void create()
{
       set("short", "天目之巔");
        set("long", @LONG
聞名天下的普渡寺，也僅是一間小小的寺廟而已，所謂山不在高有仙
則靈，像這般規模的寺廟，方圓百里，不下百座之多。天目之巔。幾塊高
聳入雲的巨石之下，寺廟依勢而立。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"way13",
  "north" : __DIR__"temple02",
]));
        set("objects", ([ 
          __DIR__"npc/man" : 1,
        ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
