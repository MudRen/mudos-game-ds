inherit ITEM;

void create()
{
        set_name("木箭",({"wood arrow","arrow"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "支");
        set("long","木頭製的弓箭, 弓箭雖然是木製的, 但是尖銳的箭鋒還是讓人冷汗直流。\n");
              }
        set("value", 20);
        set_weight(300);
        set("arrow/damage",30);       
        setup();
}

int hit(object target,object me)
{
        target->apply_condition("blooding", target->query_condition("blooding")+3);
        return 1;
}