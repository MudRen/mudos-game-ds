inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�t��", ({ "fish" }) );
        set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�N���t���F�H��A�����K��O�s�A�]�W�K�F�����C\n");
                set("unit", "��");
                set("value", 20);       
                set("heal_hp",20);      
                set("food_remaining", 5);
        }
        setup();
}


