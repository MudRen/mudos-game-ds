inherit ROOM;

void create()
{
        set("short", "�L��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room14", 
  //"north" : __DIR__"room16", 
  //"east" : __DIR__"room15",
]));
set("light",1);

        setup();
}

