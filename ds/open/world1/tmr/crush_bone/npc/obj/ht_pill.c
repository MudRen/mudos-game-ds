inherit COMBINED_ITEM;

void create()
{
    set_name("������", ({"hungry and thirsty pill", "pill" }));
    if( !clonep() ) {
        set("unit", "��");
        set("long", "�|���H�Ԩ{�l�ӹF�찧�����ĪG�C");
        set("base_unit", "��");
        set("base_value", 10 );
        set("base_weight", 20 );
    }
    set_amount(1);
    setup();
}

int stuff_ob(object me)
{
    if( me->query_stat("food") < 30 || me->query_stat("water") < 30 )
        return notify_fail("�A�S�j�S���A�A�Y�U�h�A�|��z�Ӥ`�C\n");
    
    message_vision("$N�]�U�@����������{�l�o�X�B�P�B�P���s�n�A�����}���o�ݡA�n�����F��n�X�Ӥ@�ˡC\n", me);
    me->consume_stat("food", 30);
    me->consume_stat("water", 30);
    add_amount(-1);
    return 1;
}

