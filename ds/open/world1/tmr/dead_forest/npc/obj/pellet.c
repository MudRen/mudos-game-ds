// black_pill.c

inherit COMBINED_ITEM;

void create()
{
          set_name("���C��", ({"dark-tuna pellet", "pellet" }));
        if( !clonep() ) {
                set("unit", "��");
                set("long",@long
���C�󬰻�����Ī��į�A�q�`�ͪ��󳱷t��ê��˪L�`�B�C
long
);
                set("base_unit", "��");
                set("base_value", 40 );
                set("base_weight", 20 );
        }
        set_amount(1);
        setup();
}

int stuff_ob(object me)
{
        if( me->query_stat_maximum("food") - me->query_stat("food") < 5 )
                return notify_fail("�A���{�l�w�g�ܼ��F�A�L�k�Y�U�o���į�C\n");
        message_vision("$N�r�F�@����C��A���H�۶¦�ĲG�A�C�C�a�]�F�U�h�C\n", me);
        me->consume_stat("water",30 );
        me->supplement_stat("food", 5);
        me->consume_stat("gin", 4 );
        me->supplement_stat("hp", 10 );
        me->heal_stat("hp", 15 );
        add_amount(-1);

        return 1;
}

