inherit ROOM;
void create()
{
seteuid(getuid(this_object()));
set("short","�Y�s����Q�ܮw");
set("long","\n");
set("light",1);
set("no_clean_up",1);
  set("exits",([
     "out" : "/open/world1/tmr/dragoncity/shop",
  ]));
setup();
}


