// black_pill.c

inherit COMBINED_ITEM;

void create()
{
          set_name("黑鮪草", ({"dark-tuna pellet", "pellet" }));
        if( !clonep() ) {
                set("unit", "些");
                set("long",@long
黑鮪草為頗具療效的藥草，通常生長於陰暗潮溼的森林深處。
long
);
                set("base_unit", "株");
                set("base_value", 40 );
                set("base_weight", 20 );
        }
        set_amount(1);
        setup();
}

int stuff_ob(object me)
{
        if( me->query_stat_maximum("food") - me->query_stat("food") < 5 )
                return notify_fail("你的肚子已經很撐了，無法吃下這株藥草。\n");
        message_vision("$N咬了一株黑鮪草，伴隨著黑色汁液，慢慢地吞了下去。\n", me);
        me->consume_stat("water",30 );
        me->supplement_stat("food", 5);
        me->consume_stat("gin", 4 );
        me->supplement_stat("hp", 10 );
        me->heal_stat("hp", 15 );
        add_amount(-1);

        return 1;
}

