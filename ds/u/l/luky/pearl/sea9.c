// This is a room made by roommaker.
inherit ROOM;
void create()
{
set("short", "������");
set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
);
set("exits", ([ 
  "east" : __DIR__"sea3",
  "north" : __DIR__"sea1",
]));
set("no_clean_up", 0);
setup();
replace_program(ROOM);
}
