inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room17", 
  "northeast" : __DIR__"room21", 
  //"east" : __DIR__"room17",
  //"west" : __DIR__"room17",
]));
set("light",1);

        setup();
}

