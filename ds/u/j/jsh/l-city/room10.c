inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room12", 
  "east" : __DIR__"room9", 
  "west" : __DIR__"room11",]));
set("light",1);

        setup();
}

