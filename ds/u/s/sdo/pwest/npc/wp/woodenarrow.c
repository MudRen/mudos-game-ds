inherit ITEM;

void create()
{
        set_name("����b",({"wooden arrow","arrow"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","����һs�����b�A���ʫܱj�A����í�w�C\n");
              }
        set("value", 25);
        set_weight(300);
        set("arrow/damage",35);       
        setup();
}

int hit(object target,object me)
{
        target->apply_condition("blooding", target->query_condition("blooding")+4);
        return 1;
}

