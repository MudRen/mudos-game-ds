// dumpling.c �]�l

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�]�l", ({"baozi", "dumpling"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�@�ӭ��Q�Q���ץ]�l�C\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 3);
                set("food_supply", 20);
        }
}
