// cookie.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�I��", ({ "cookie" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�Ӭݰ_���Z�n�Y���I�ߡC\n");
                set("unit", "��");
                set("value", 0);       //�Ѧһ��欰�^�_�I���`�M���H5
                set("heal_hp",10);      //�i�H�O"heal_hp"�άO"heal_mp",�]�i�H����.
                set("heal_mp",10);
                set("food_remaining", 2);
        }
        setup();
}

