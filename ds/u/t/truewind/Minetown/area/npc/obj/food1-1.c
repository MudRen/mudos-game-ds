inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�@�Y��i���~", ({ "condensed food","food" }) );
        set_weight(100);
                set("long", "�콦�]�۪��@�Ӥ�έ��~���A���Y�O���׿@�Y����i���~�C\n");
                set("drink_msg","$N���_$n�A��F�]�ˡA�j�f�j�f�Y�����Y�������C\n");
                set("finish_drink_msg","$N�N�ѤU��$n�Y���F�C\n");
                set("unit", "�]");
                set("value", 100);       //�Ѧһ��欰�^�_�I���`�M���H5
                set("heal_hp",35);      //�i�H�O"heal_hp"�άO"heal_mp",�]�i�H����.
                set("heal_ap",25);
                set("food_remaining", 2);
        setup();
}
