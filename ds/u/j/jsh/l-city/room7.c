inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room5", 
  //"west" : __DIR__"room6", 
  "northeast" : __DIR__"room8",]));
set("light",1);

        setup();
}

