
inherit ROOM;
void create()
{
set("short", "爛當鋪");
set("long", @LONG
這是一間爛當鋪
LONG
        );
set("exits", ([ "out" 
: __DIR__"workroom",
]));
set("objects", ([
 __DIR__"boss" : 1,
    ]));

set("room_type","shop");
set("no_clean_up", 0);
set("light",1);
setup();
}

