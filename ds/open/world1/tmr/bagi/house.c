// Room: /open/world1/tmr/bagi/house.c

inherit ROOM;
void open_star2() {
    "/adm/daemons/event/bagistar.c"->trigger_event();
}

void open_star() {
    call_out("open_star2", 60+random(30));
}
void create()
{
        set("short", "竹屋內");
        set("long", @LONG
你正在一間翠竹碧綠帶著泌香的竹屋內，屋內的一桌一椅等家具皆乃
綠竹編成，整間屋子雖處在高山雪地之中，你卻不覺得寒冷。竹桌上正沏
著一壺清香的茶葉。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "east" : __DIR__"ghat2",
        ]));
        set("objects",([
        __DIR__"npc/advmaster":1,
        ]) );
        set("light",1);        
        set("valid_startroom",1);
        set("world", "past");
        set("no_clean_up", 0);

        setup();
}

