// guild.c改自vendor.c

inherit ROOM;

void create()
{
seteuid(getuid(this_object()));
set("short","林奇的倉庫");
set("long","\n");
set("light",1);
set("no_clean_up",1);
set("objects",([

 ]));
set("exits", ([	//出口設於NPC位置,可以不設
"out":"/open/world2/lichi_town_2/map_12_11",
]));
setup();
}

