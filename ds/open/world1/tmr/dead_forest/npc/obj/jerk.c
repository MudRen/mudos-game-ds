inherit COMBINED_ITEM;

void create()
{
        set_name( "���װ�" , ({"bear jerk", "jerk"}));
        if( !clonep() ) {
                set("unit", "��");
                set("long",@long
�o�O�@�����������װ��A���ѿ@�p���{���A���H�D�ۤ��T�@�ð_�ӡC
long
);
                 set("base_unit", "��");
                set("base_value", 40) ;
                set("base_weight", 20 );
        }
        set_amount(1);
        setup();
}

int stuff_ob(object me)
{
        if( me->query_stat_maximum("food") - me->query_stat("food") < 5 )
                  return notify_fail("�A���{�l�w�g�ܼ��F�A�L�k�Y�U�o���װ��C\n");
        message_vision("$N�Y�U�@���{û���װ��A�y�W�S�X�h�W�����C\n", me);
        me->consume_stat("water",30 );
        me->supplement_stat("food", 5);
        me->supplement_stat( "gin" , 10 );
        me->heal_stat("gin", 15 );
        add_amount(-1);

        return 1;
}

