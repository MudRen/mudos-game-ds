inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room3", 
  "west" : __DIR__"room5",
]));
set("light",1);

        setup();
}

