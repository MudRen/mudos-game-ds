#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("烈日匕首",({"sun dagger","dagger"}));
	set("long",@LONG
這是一把橘紅色的匕首。鮮豔的色彩就像是鮮血一般，會
讓使用者的心中產生一股莫名的殺意。
[可儲存裝備]
LONG
);
	set_weight(5600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("material","iron");
		set("no_sac",1);
        }
        set("value",3480);
    	set("weapon_prop/bar",1);
    	set("weapon_prop/sou",-1);
	set("weapon_prop/dodge",5);
    	set("weapon_prop/perception",6);
    	set("weapon_prop/hit",11);
	set("backstab_bonus",36);
	init_dagger(15);
        setup();
}

void attack(object me,object victim)
{
        ::attack();
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(11)) return; // 1/20 的機率出現特攻
	if(me->query("evil")<800)
	{
		tell_object(me,"你突然有一股很想殺人的慾望，你的人格似乎越來越邪惡了。\n");
		me->add("evil",random(10));
	}
	return;
}

int query_autoload() { return 1; }

