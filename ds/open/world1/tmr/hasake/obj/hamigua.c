// hamigua.c
// Jay 3/18/96

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���K��", ({"hami melon", "melon"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�@�����������K�ʡC���Y���K�ʵ���ըӦ��C\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining",5);
                set("heal_hp", 10);  
        }
}

