inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�T���v", ({ "sandwich" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�ӥ]�۽ަסB���檺�T���v�A�ݨӤQ���i�f�C\n");
                set("unit", "��");
                set("value", 30);  
                set("food_remaining",3);
                set("heal_hp",5);  
        }
}


