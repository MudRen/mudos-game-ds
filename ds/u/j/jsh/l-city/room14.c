inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room13", 
  "north" : __DIR__"room16", 
  "east" : __DIR__"room15",
]));
set("light",1);

        setup();
}

