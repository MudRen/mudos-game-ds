inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�]�ˤj�氮", ({ "packed cookie","cookie" }) );
        set_weight(40);
        {
                set("long", "�@���j�j���S�s�氮�A�ݰ_�ӫܴ��q���ˤl�A�ڻ��Y�F���q�믫�C\n");
                set("unit", "��");
                set("value", 100);       //�Ѧһ��欰�^�_�I���`�M���H5
                set("heal_hp",70);      //�i�H�O"heal_hp"�άO"heal_mp",�]�i�H����.
                set("heal_mp",5);
                set("food_remaining", 5);
        }
        setup();
}