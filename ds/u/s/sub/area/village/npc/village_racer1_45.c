#include <ansi.h>
inherit NPC;
void create()
{
    set_name("羅西",({"Valentino Rossi","valentino","rossi"}));
    set("long",@LONG
Valentino可以說是為了GP所出生的，因為他的父親Graziano Rossi 
曾經也是一個賽車手。 

生日：1976年2月16日
出生地：義大利 Urbino
星座：水瓶座
身高、體重：180cm、70kg

LONG);
    set("level",45);
    set("title","飆車族");
    set("age",24+random(2));
    set("combat_exp",50000);
    set("nickname","[0;1;33m�[1mp[1m�[1m�[1m�[1mL[0m");
        setup();
carry_object(__DIR__"eq/arai_armor_25")->wear();
carry_object(__DIR__"eq/arai_boots_12")->wear();
carry_object(__DIR__"eq/arai_cloth_22")->wear();
}
