inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"room1", 
  "west" : __DIR__"room3",]));
set("light",1);

        setup();
}

