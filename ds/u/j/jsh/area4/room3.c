inherit ROOM;

void create()
{
        set("short", "�n�j��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"room-1",  
  "west" : __DIR__"room4",  
"southeast" : __DIR__"room_1", 
"north" : __DIR__"room2",]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

