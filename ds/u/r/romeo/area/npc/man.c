#include <ansi.h>
inherit NPC;
void create()
{
set_name("中國殭屍", ({"man"}) );
set("age",30);
set("long","一具商朝時代的高官，因為含冤而死，心中有所不快
，所以跟著秦始皇來到人間肆虐。\n");
set("attitude", "aggressive");
set("level",20);
setup();
}

