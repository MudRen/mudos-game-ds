inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("山泉水", ({ "water" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一瓶裝有山泉的瓶子。\n");
                set("unit", "瓶");
                set("value", 80);       
                set("heal_mp",10);      
                 set("water_remaining", 5);
        }
}

