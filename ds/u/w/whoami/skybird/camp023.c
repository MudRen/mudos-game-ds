inherit ROOM;

void create()
{
        set("short", "後勤車隊");
        set("long", @LONG
這裡是一區由數輛馬車互相以鐵鍊串起並圍起來的一塊空地
，軒。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"camp022",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

