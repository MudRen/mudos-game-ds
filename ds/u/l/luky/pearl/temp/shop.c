// guild.c���vendor.c
inherit ROOM;
void create()
{
seteuid(getuid(this_object()));
set("short","�R���˳ƼȦs�ө�");
set("light",1);
set("no_clean_up",1);
setup();
set("no_clean_up",1);
}
