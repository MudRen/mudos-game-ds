#include <ansi.h>
inherit NPC;
void create()
{
set_name("村人", ({"man"}) );
set("age",30);
set("long","不知是從那來的，十分神秘的人物。\n");
set("level",10);
setup();
}

void die()
{
message("world:world3:vision",
HIM"                   化裝村人的盜賊臨死前施放出藏在懷裡的狼煙。\n\n"+NOR
	,users());
environment(this_object())->set("war",1);
::die();
}

