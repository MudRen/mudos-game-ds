inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("豬肉", ({ "meat" }) );
        set_weight(60);
        if( clonep() )
             set_default_object(__FILE__);
        else {
             set("long", "一片經壓製的小片豬肉，看上去不怎特別。\n");
             set("unit", "片");
             set("value", 30);  
             set("food_remaining",2);
             set("heal_hp",10);  
        }
}
