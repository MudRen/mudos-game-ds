inherit ITEM;
inherit F_PILL;
inherit F_FOOD;
void create()
{
        set_name("甘泉水", ({ "sweat water","water" }) );
        set_weight(110);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一袋清澈透明略帶香氣的山泉。\n");
                set("unit", "袋");
                set("value", 50);       //參考價格為回復點數總和除以5
                set("heal_mp",25);      //可以是"heal_hp"或是"heal_mp",
                set("heal_body",10);    //"heal_head" ,"heal_body"
                set("heal_head",7);    //"heal_hand" ,"heal_foot"也可以都有.
             set("heal_hand",5);
                set("heal_foot",3);  
                set("food_remaining", 5);
                //食用訊息 eat_msg 可以用 $N 表玩家, $n表此物.(房間都會看到)
                set("eat_msg","$N打開了一袋$n, 輕輕喝了一口，甘甘甜甜，味道挺好喝的。");
                //效果訊息 eff_msg 不可用$N 及 $n (因為只有玩家會看到)
                set("eff_msg","你覺得突然一股清涼的氣息流過全身。");
        }
        setup();
}

