inherit ROOM;

void create()
{

set("short","中庭");
set("long", @LONG
你正站在偌大的庭院, 在你的旁邊有許多的花草, 讓你覺得非常高興
, 你的前方有一條長長的走道, 長道是由青磚所構成的, 你深深覺得有錢
人家就是不一樣.
LONG
);
set("world", "past");
set("light",1);
set("exits", ([                
         "south" : __DIR__"horse_2.c", 
         "north" : __DIR__"aa_2.c", 
   ]));

 setup();
}


