inherit ITEM;
void create()
{

       set_name("���нb",({"gold plume arrow","arrow"}));
       if( clonep() )
         set_default_object(__FILE__);
       else {
          set("unit", "��");
          set("long","�Ѽ��K���y���}�b�A�b�b�����Ӫ���Ф򰵸˹��C\n");
            }
        set("value", 100);
        set_weight(250);
        set("arrow/damage",25);         //���ˤO
       setup();
}
int hit(object target,object me)
{
        target->apply_condition("blooding", target->query_condition("blooding")+3);
        return 1;
}
