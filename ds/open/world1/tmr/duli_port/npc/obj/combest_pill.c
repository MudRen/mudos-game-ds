inherit COMBINED_ITEM;

void create()
{
        set_name("�d�J�O�٤Y", ({ "comebest pill", "pill"}));
        if( !clonep() ) {
                set("unit", "��");
                set("long",@long
�o�O�@���H�K����b�ĩ��R�쪺�ĤY�A����_�믫�������Ī��C
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
                return notify_fail("�A���{�l�w�g�ܼ��F�A�L�k�Y�U�o���ĤY�C\n");
        message_vision("$N�Y�U�F�@�ɱd�J�O�٤Y�C\n", me);
        me->consume_stat("water",20 );
        me->supplement_stat("food", 5);
        me->supplement_stat("gin", 15);
        add_amount(-1);
        return 1;
}

