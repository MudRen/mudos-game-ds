inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("�c�l�G��", ({ "fruit" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�Ӧh�ġA�������G�סC\n");
                set("unit", "��");
                set("value",200);
                set("heal_hp",30);
                set("food_remaining",2);
        }
     setup();
}
