inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  //"north" : __DIR__"room7", 
  //"west" : __DIR__"room6", 
  "east" : __DIR__"room5",]));
set("light",1);

        setup();
}

