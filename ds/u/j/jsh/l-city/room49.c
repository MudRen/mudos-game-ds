inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"room48", 
  "northeast" : __DIR__"room47", 
  "west" : __DIR__"room50", 
  //"west" : __DIR__"room48",
]));
set("light",1);

        setup();
}

