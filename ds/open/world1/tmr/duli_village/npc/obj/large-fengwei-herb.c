inherit COMBINED_ITEM;

void create()
{
        set_name("�j�����", ({"large feng-wei herb", "feng-wei", "herb"}));
        if( !clonep() ) {
                set("unit", "��");
                set("long",@long
�����˺�O���`�����į�A���G�㦳�����_����_�\�ġA���O���
���q�H�N�S����γB���ˤl�C�o�O�@�����j�������A�W�Y���󸭤]
��@�몺���A�v���h�C
long
);
                set("base_unit", "��");
                 set("base_value", 1000);
                set("base_weight", 10);
        }
        set_amount(1);
        setup();
}

int stuff_ob(object me)
{
        if( me->query_stat_maximum("food") - me->query_stat("food") < 10 )
                return notify_fail("�A���{�l�w�g���o����F��]�]���U�h�F�C\n");
        message_vision("$N���X�@��j������J�f���B��O�O�a�Z�F�Z�]�F�U�h�C\n", me);
        me->consume_stat("water", 10);
        me->supplement_stat("food", 10);
        me->consume_stat("gin", 5);
        me->supplement_stat("nina", 50);
          me->heal_stat("nina", 5);
        add_amount(-1);
        return 1;
}

