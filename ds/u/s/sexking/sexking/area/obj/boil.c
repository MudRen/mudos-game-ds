inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���F�N", ({ "gun don boil","boil" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long", "�o�O�J�R���饻���������F�N�A�̭����ܦh�p�Y�A���I�I���Q���i�f�C\n");
                set("unit", "�J");
                set("eat_msg","$N�N$n�̪��½����X�Ӥ@�f��٤F�U�h�C\n");
                set("finish_msg","$N�N$n�����̦害�X�Ӥ@�f��٤F�U�h�C\n");
        set("value", 200);
        set("heal_ap",30);
        set("heal_hp",30);
        set("food_remaining", 2);
}
setup();
}
