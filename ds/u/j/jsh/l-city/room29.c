inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room28", 
  //"south" : __DIR__"room29", 
  //"east" : __DIR__"room25", 
  "west" : __DIR__"room30",
]));
set("light",1);

        setup();
}

