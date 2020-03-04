#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name("血刺",({"blood needle","needle"}));
	set("long",@LONG
這是一支鮮紅色的鋼釘。當你看到這把狠毒的武器時不禁冷汗直流，
血刺散發出來的殺氣使你感到呼吸困難。

LONG
);
	set_weight(6600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "根");
		set("material","iron");
		set("no_sac",1);
        }
        set("value",4380);
        set("volume",1);
    	set("weapon_prop/bar",1);
    	set("weapon_prop/sou",-1);
	set("weapon_prop/dodge",5);
    	set("weapon_prop/perception",6);
    	set("weapon_prop/hit",11);
	set("backstab_bonus",36);
	init_dagger(41);
        setup();
}

void attack(object me,object victim)
{
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(11)) return; // 1/20 的機率出現特攻
	if(me->query("evil")<800)
	{
		tell_object(me,"你突然有一股很想殺人的慾望，你的人格似乎越來越邪惡了。\n");
		me->add("evil",3+random(10));
	}
	return;
}


