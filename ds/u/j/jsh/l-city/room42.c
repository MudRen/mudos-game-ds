inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  //"north" : __DIR__"room38", 
  //"southwest" : __DIR__"room41", 
  "east" : __DIR__"room3", 
  "west" : __DIR__"room43",
]));
set("light",1);

        setup();
}

