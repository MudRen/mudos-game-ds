inherit ITEM;

void create()
{

        set_name("������b",({"steel arrow","arrow"}));
        set_weight(500);
        set("long","�o�O�@�Ӥ��ų]�p��������b, ���ӥB�j��, �y�U���b�Y�i�y�����j�}�a�C\n");
        if( clonep() )
           set_default_object(__FILE__);
        else {
           set("unit", "��");
           set("material","steel");
          set("value",75);
        }
   set("arrow/damage",60);
	setup();
}
int hit(object target,object me)
{
    target->apply_condition("blooding", target->query_condition("blooding")+3);
     return 1;
}
