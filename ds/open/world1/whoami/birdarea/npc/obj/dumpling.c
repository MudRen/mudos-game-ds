inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�ץ]�l", ({ "dumpling" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�Ӽ����˪����ץ]�l�A�ݨӺ��n�Y���ˤl�C\n");
                set("unit", "��");
                set("value", 60);  
                set("food_remaining",2);
                set("heal_hp",20);  
        }
}
