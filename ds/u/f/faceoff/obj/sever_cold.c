inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("�C�H", ({ "seven cold", "cold" }));
        set("long",@LONG
�o�O�@�ؤ��Ī��ħ�, �ѩ��ĩʷ��H, �q�`���O�Φb�ޥX�A�Ϊ�
����F�O, �B���y�ͦY.
LONG
);
        set_weight(55);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material","plant");
                set("value", 25);
                set("attr/wound",1);  
                set("heal_hp",10);
		set("heal_mp",20);
                set("attr_one","plant"); 
                set("attr_two","yin");  
        }
        setup();
}