inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("百花釀", ({ "flower wine","wine" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一袋青綠色外皮的酒袋。");
                set("unit", "袋");
        }
                set("value", 100);       
                set("heal_mp",5);      
                set("heal_ap",10);
                set("heal_hp",5);
                set("water_remaining", 5);
       setup();
}
