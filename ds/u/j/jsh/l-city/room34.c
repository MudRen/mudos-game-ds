inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  //"north" : __DIR__"room32", 
  "south" : __DIR__"room36", 
  "east" : __DIR__"room35", 
  "west" : __DIR__"room33",
]));
set("light",1);

        setup();
}

