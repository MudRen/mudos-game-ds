// guild.c改自vendor.c
inherit ROOM;
void create()
{
seteuid(getuid(this_object()));
set("short","愛爾裝備暫存商店");
set("light",1);
set("no_clean_up",1);
setup();
set("no_clean_up",1);
}
