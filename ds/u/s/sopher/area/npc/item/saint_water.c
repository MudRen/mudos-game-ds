inherit ITEM;
inherit F_WATER;
void create()
{
     set_name("聖水", ({ "water" }) );
     set_weight(100);
     if( clonep() )
         set_default_object(__FILE__);
     else {
         set("long", "一瓶散發出魔力的瓶子。\n");
         set("unit", "瓶");
         set("value", 16);
         set("heal_mp",1);
         set("water_remaining", 3);
         }
setup();
}

