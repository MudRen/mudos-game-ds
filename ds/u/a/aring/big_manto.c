inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�W�j�C�Y", ({ "manto" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�Ӽ����˪��W�j���C�Y�A�ݨӺ��n�Y���ˤl�C\n");
                set("unit", "��");
                set("value", 10);  
                set("food_remaining",2);
                set("heal_hp",50);  
        }
}

