inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"south" : __DIR__"room16", 
  //"north" : __DIR__"room20", 
  //"east" : __DIR__"room17",
  "west" : __DIR__"room17",
]));
set("light",1);

        setup();
}

