inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�j�ɤY", ({ "big pill","pill" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@�������窺�Y�l, ���o�X�@�ѭ��� \n");
                set("unit","��");
                set("value",120);
                set("heal_ap",30);
                set("food_remaining",3);
        }
}

