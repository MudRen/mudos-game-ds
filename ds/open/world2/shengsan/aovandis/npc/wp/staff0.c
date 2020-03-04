#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name("紅色木杖", ({ "red wood staff","wood staff","staff" }) );
	set_weight(7350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
這是一把紅色的木杖, 杖頭鑲了一顆紅色的圓形石頭, 
當你看著這把杖時, 覺得有一股奇妙的力量灌進了你的大
腦。
LONG
);
		set("value", 2210);
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
    set("wield_msg",HIM"$N"HIM"緊緊握住$n"HIM", 身體周圍繞起陣陣紅暈!!\n"NOR);
    set("unwield_msg","$N緩緩的將$n插回腰間。\n"NOR);
    init_staff(21);
    setup();
}

void attack(object me,object victim)
{
  ::attack();
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(20)) return; // 1/20 的機率出現特攻
	message_vision(HIR"$N"HIR"手上的$n"HIR"發出一道紅色的光芒。\n"NOR,me,this_object());
	tell_object(me,"你的精神似乎回復了一些。\n");
	me->receive_heal("mp",10+random(me->query("level")*2));
	return;
}
