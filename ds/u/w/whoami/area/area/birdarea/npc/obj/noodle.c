inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�t����", ({ "noodle" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�J�����˪��t���ѡA�ݨӺ��n�Y���ˤl�C\n");
                set("unit", "�J");
                set("value", 80);  
                set("food_remaining",3);
                set("heal_hp",30);  
        }
}

