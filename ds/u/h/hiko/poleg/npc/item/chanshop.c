inherit ROOM;
void create()
{
seteuid(getuid(this_object()));
set("short","�l�㪺�ܮw");
set("long","\n");
set("light",1);
set("no_clean_up",1);
  set("exits",([
       "out" : "/u/h/hiko/poleg/po8n",
  ]));
setup();
}

