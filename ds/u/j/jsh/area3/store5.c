inherit ROOM;

void create()
{
        set("short", "�B�F����");
        set("long", @LONG
test

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"store2",
  "west" : __DIR__"store6",  
  "east" : __DIR__"store3",]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

