inherit ITEM;
void create()
{

       set_name("金羽箭",({"gold plume arrow","arrow"}));
       if( clonep() )
         set_default_object(__FILE__);
       else {
          set("unit", "支");
          set("long","由熟鐵打造的弓箭，在箭尾有個金色羽毛做裝飾。\n");
            }
        set("value", 100);
        set_weight(250);
        set("arrow/damage",25);         //殺傷力
       setup();
}
int hit(object target,object me)
{
        target->apply_condition("blooding", target->query_condition("blooding")+3);
        return 1;
}
