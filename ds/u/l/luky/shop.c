// guild.c���vendor.c

inherit ROOM;

void create()
{
seteuid(getuid(this_object()));
set("short","�L���󪺭ܮw");
set("long","\n");
set("light",1);
set("no_clean_up",1);
set("objects",([
 "/u/l/luky/npc/item/bag":1,
 "/u/l/luky/npc/eq/blackjacket":3,
 "/u/l/luky/npc/wp/kaisan_b":1,
 ]));
set("exits", ([	//�X�f�]��NPC��m,�i�H���]
"out":"/open/world2/anfernee/start/bug",
]));
setup();
}

