inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room8", 
  //"west" : __DIR__"room6", 
  "west" : __DIR__"room10",]));
set("light",1);

        setup();
}

