inherit ROOM;

void create()
{
        set("short", "�Y�s��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"room20", 
  "east" :  __DIR__"room2", 
  "south" : __DIR__"startroom",
  "northeast" : __DIR__"room11",]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

