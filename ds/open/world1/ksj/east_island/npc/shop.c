inherit ROOM;

void create()
{
seteuid(getuid(this_object()));
set("short","�F��q���ܮw");
set("long","\n");
set("light",1);
set("no_clean_up",1);
setup();
}
