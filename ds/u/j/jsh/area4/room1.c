inherit ROOM;

void create()
{
        set("short", "�n�j��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"room2", 
  "north" : "/open/world1/tmr/area/street5",]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

