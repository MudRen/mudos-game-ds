inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("�ʨ�", ({ "bate grass", "grass" }));
        set("long",@LONG
�o�O�@�ثD�`�`���������ħ�, �ĩ��ݶ�, �]�L��j�P�Ӥ��y
�ͭ�, �q�`�Ω󤺶�.
LONG
);
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material","plant");
                set("value", 30);
                set("attr/wound",1);  
                set("heal_mp",10);
		set("heal_ap",20);
                set("attr_one","plant"); 
                set("attr_two","yang");  
        }
        setup();
}
