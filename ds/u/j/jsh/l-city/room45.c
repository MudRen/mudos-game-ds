inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  //"southwest" : __DIR__"room46", 
  //"northwest" : __DIR__"room45", 
  "southeast" : __DIR__"room44", 
  "west" : __DIR__"room47",
]));
set("light",1);

        setup();
}

