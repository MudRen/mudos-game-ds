// black_pill.c

inherit COMBINED_ITEM;

void create()
{
         set_name("鯨魚草", ({"whale pellet", "pellet","_OBJ_ID_WHALE_PELLET_"}));


        if( !clonep() ) {
                set("unit", "些");
                set("long",@long
這是一株盛產於鯨魚島上的藥草，對於療傷頗有功效。
long
);
                set("base_unit", "株");
                set("base_value", 20);
                set("base_weight", 20);
        }
        set_amount(1);
        setup();
}

int stuff_ob(object me)
{
        if( me->query_stat_maximum("food") - me->query_stat("food") < 5 )
                return notify_fail("你的肚子已經很撐了，無法吃下這株藥草。\n");
        message_vision("$N咬了一株鯨魚草，隨即吞了下去。\n", me);
        me->consume_stat("water",30 );
        me->supplement_stat("food", 5);
        me->consume_stat("gin", 2);
        me->supplement_stat("hp", 5);
        me->heal_stat("hp", 10);
        add_amount(-1);

        return 1;
}

