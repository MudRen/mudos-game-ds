inherit COMBINED_ITEM;

void create()
{
        set_name( "��װ�" , ({"lion jerk", "jerk"}));
        if( !clonep() ) {
                set("unit", "��");
                set("long",@long
�o�O�@����������װ��A�D�_�Ӧ��I�Ļ����ߡA�����D�|�_�Ө��D�p��C
long
);
                 set("base_unit", "��");
                set("base_value", 20) ;
                set("base_weight", 20 );
        }
        set_amount(1);
        setup();
}

int stuff_ob(object me)
{
        if( me->query_stat_maximum("food") - me->query_stat("food") < 5 )
                  return notify_fail("�A���{�l�w�g�ܼ��F�A�L�k�Y�U�o���װ��C\n");
        message_vision("$N�Y�U�@���o�Ī��װ��A�y�W���⤣�O�ܦn�ݡC\n", me);
        me->consume_stat("water",30 );
        me->supplement_stat("food", 5);
        me->supplement_stat( "gin" , 30 );
        add_amount(-1);
        return 1;
}

