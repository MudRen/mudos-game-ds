inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("鮮魚", ({ "caller" }) );
        set_weight(240);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一條活蹦亂跳的鮮魚，大概才剛被抓到不久•\n");
                set("unit", "條");
                set("value", 260);  
                set("food_remaining",2);
                set("heal_hp",130);   
                set("heal_ap",180);  
                set("heal_mp",140);  
        }
}

