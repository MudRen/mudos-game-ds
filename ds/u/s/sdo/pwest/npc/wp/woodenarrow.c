inherit ITEM;

void create()
{
        set_name("杉木箭",({"wooden arrow","arrow"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "支");
        set("long","杉木所製成的箭，韌性很強，飛行穩定。\n");
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

