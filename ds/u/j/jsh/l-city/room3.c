inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room2", 
  "west" : __DIR__"room42",
  "north" : __DIR__"room4",
  "southwest" : __DIR__"room22",]));
set("light",1);

        setup();
}

