// kaoya.c �N�n

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�N�n", ({"kaoya", "ya"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�@�u�αo�y�o���_�ʯN�n�C\n");
                set("unit", "�u");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}
