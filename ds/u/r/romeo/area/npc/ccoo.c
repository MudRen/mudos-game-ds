#include <ansi.h>
inherit NPC;
void create()
{
set_name("殺人狂", ({"cool"}) );
set("age",30);
set("long","這是一個被叛死刑的囚犯，滿臉刀疤，殺的人已經連自己都不知道
了，多看他一眼你也可能成為它的獵物之一喔。\n");
set("attitude", "aggressive");
set("level",22);
set_skill("dagger",70);
setup();
carry_object(__DIR__"wp/dagger")->wield();
}
