inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("天香甘露", ({ "sky water","water" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","這是一瓶只有在天香客棧才買得到的天香甘露，有提神醒腦的效用。\n");
                set("unit", "瓶");
                 set("value",54);
           set("heal_hp",8);
              set("heal_mp",10);
                set("water_remaining", 3);
        }
     setup();
}
