inherit ROOM;

void create()
{
          set("short", "杜尼旅店");
          set("long", @LONG
這是一間離港口最近的旅店，也因此常常住滿了過往的旅客、水手、
船伕等，可說是閒雜人等，一應具全，但也因為人脈廣闊，在這裡可以問
到許多消息。旅店門口掛了張木製招牌，瞧樣子，也算是歷史久遠了。
LONG
          );
        set("exits", ([ /* 1 element(s) */
                "west" : __DIR__"map_14_16",
        ]));

        set("valid_startroom", 1);
        set("objects",([
        __DIR__"npc/waiter":1,
          "/obj/statue":1,
        ]));
        set("no_fight", 1);
        setup();
}

