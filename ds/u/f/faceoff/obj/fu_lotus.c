inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("�B��", ({ "fu lotus", "lotus" }));
        set("long",@LONG
�o�O�@�ؤ��ͪ������ħ�, �ĩ��ݶ�, �P�a���@��, ���ǳ\���r
��, ���g�һs��K�L�r, �q�`�Ω�ж�, ������������.
LONG
);
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material","plant");
                set("value", 15);
                set("attr/wound",1);  
                set("heal_hp",20);
                set("heal_ap",5);
                set("heal_mp",5);
                set("attr_one","plant"); 
                set("attr_two","yang");  
        }
        setup();
}
