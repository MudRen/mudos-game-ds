inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("地錢", ({ "ti chnu", "chnu" }));
        set("long",@LONG
這是一種長在地面上, 約莫一寸高的中藥藥材, 雖然沒有七寒
來的寒, 卻含有些毒素, 經過煉製後, 對於各方面的效果也都平平
, 並沒有特別突出.
LONG
);
        set_weight(45);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("material","plant");
                set("value", 15);
                set("attr/wound",1);  
                set("heal_ap",10);
                set("heal_hp",10);
		set("heal_mp",10);
                set("attr_one","plant"); 
                set("attr_two","yin");  
                set("food_remaining", 1);  
                set("eat_msg","$N吞下一個地錢\n");
                set("eff_msg","你頓覺胸口氣悶難受, 腹痛如絞 ! !\n");
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me;
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        me=this_player();
        if(me->query("mp")<19)
        {
                return notify_fail("你的精神力(MP)已經不夠了, 再吃就破表囉。\n");
        }
        else
        {
                me->receive_damage("mp",20);      
                me->receive_damage("ap",20);      
                return ::do_eat(arg);
        }
}
