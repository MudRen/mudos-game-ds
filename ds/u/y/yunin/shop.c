
inherit ROOM;
void create()
{
set("short", "���Q");
set("long", @LONG
�o�O�@�����Q
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

