inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�j�ɤY", ({ "big pill","pill" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@�������窺�Y�l�A���o�X�@�ѭ����E\n");
                set("unit","��");
                set("value",200);
                set("heal_ap",50);
                set("food_remaining",3+random(3));
        }
}

