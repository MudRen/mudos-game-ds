// guild.c改自vendor.c

inherit ROOM;

void create()
{
seteuid(getuid(this_object()));
set("short","林老闆的倉庫");
set("long","\n");
set("light",1);
set("no_clean_up",1);
set("objects",([
 __DIR__"item/bag":1,
 __DIR__"eq/blackjacket":3,
 __DIR__"wp/kaisan_b":1,
 ]));
set("exits", ([	//出口設於NPC位置,可以不設
"out":"/open/world2/anfernee/start/bug",
]));
setup();
}

