inherit ROOM;

void create()
{
        set("short", "步靈市集");
        set("long", @LONG
這裡是步靈城內，新興的市場，其實都是老面孔，他們大多都是
步靈城的居民，在此市場都有一些新研發出來的東西，不過價格比外
面的還貴，必竟這兒的東西，都是真材實料。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"store3", 
  "west" : __DIR__"store2", 
  "east" : "/open/world1/cominging/area/bsouth3",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"sellman1" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

