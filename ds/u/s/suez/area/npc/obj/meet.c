inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�װ�", ({ "meet" }) );
        set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@���װ��A�����D�Τ��򭻮ƽը��A�����X�_�C\n");
                set("unit", "��");
                set("value", 20);       //�Ѧһ��欰�^�_�I���`�M���H5
                set("heal_hp",20);      //�i�H�O"heal_hp"�άO"heal_mp",�]�i�H����.
                set("food_remaining", 5);
        }
        setup();
}
