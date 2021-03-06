#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(HIC"月光杖"NOR, ({ "moon staff","staff" }) );
	set_weight(10350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把古老的木杖, 杖頭鑲了一顆水藍色的圓形寶石, \n"
                            "當你看著這把杖時, 似乎覺得心情十分平靜, 週遭所發生\n"
                            "的事情也能夠觀察的很清楚。\n[可儲存裝備]\n");
		set("value", 4210);
		//set("no_sell",1);
		set("no_sac",1);
		set("material", "wood");
	}
    set("weapon_prop/sou",1);
    set("weapon_prop/bar",-1);
    set("weapon_prop/int",1);
    set("weapon_prop/parry",8);
    set("weapon_prop/perception",8);
    set("weapon_prop/hit",8);
    set("wield_msg",HIC"$N"HIC"緊緊握住$n"HIC", 眼光似乎銳利了許\多!!\n"NOR);
    set("unwield_msg",HIC"$N"HIC"沉著的將$n"HIC"插回腰間。\n"NOR);
    init_staff(16);
    setup();
}

void attack(object me,object victim)
{
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(40)) return; // 1/40 的機率出現特攻
	message_vision(HIC"$N"HIC"手上的$n"HIC"發出淡淡的光芒。\n"NOR,me,this_object());
	tell_object(me,"你的精神似乎回復了。\n");
	me->receive_heal("mp",20+random(me->query("level")*2));
	return;
}

int query_autoload() { return 1; }