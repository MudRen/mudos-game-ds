inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  //"south" : __DIR__"room23", 
  "north" : __DIR__"room22", 
  "west" : __DIR__"room24",
]));
set("light",1);

        setup();
}

