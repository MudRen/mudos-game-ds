inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  //"north" : __DIR__"room24", 
  //"south" : __DIR__"room28", 
  //"east" : __DIR__"room27", 
  "west" : __DIR__"room25",
]));
set("light",1);

        setup();
}

