inherit COMBINED_ITEM;

void create()
{
          set_name("�H����", ({"whale pellet", "pellet","_OBJ_ID_WHALE_PELLET_"}));
        if( !clonep() ) {
                set("unit", "��");
                set("long",@long
�o�O�@�貱�����H���q�W���į�A������˻ᦳ�\�ġC
long
);
                set("base_unit", "��");
                set("base_value", 20);
                set("base_weight", 20);
        }
        set_amount(1);
        setup();
}

int stuff_ob(object me)
{
        if( me->query_stat_maximum("food") - me->query_stat("food") < 5 )
                return notify_fail("�A���{�l�w�g�ܼ��F�A�L�k�Y�U�o���į�C\n");
        message_vision("$N�r�F�@���H����A�H�Y�]�F�U�h�C\n", me);
        me->consume_stat("water",30 );
        me->supplement_stat("food", 5);
        me->consume_stat("gin", 2);
        me->supplement_stat("hp", 5);
        me->heal_stat("hp", 10);
        add_amount(-1);

        return 1;
}

