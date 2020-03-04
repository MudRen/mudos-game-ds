inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("噴水池", ({ "pot" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("no_get",1);
		set("no_sac",1);
                set("long", "一個噴水池，置放在地上，給過往的人飲用。\n");
set("unit","座");
                set("value", 20);
                set("heal_hp",100);
                set("eat_func",5); //等級5以內可以無限使用.
                set("water_remaining", 100);
        }
}

