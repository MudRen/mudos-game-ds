inherit ITEM;
inherit F_PILL;
inherit F_FOOD;
void create()
{
        set_name("�̬u��", ({ "sweat water","water" }) );
        set_weight(110);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�U�M���z�����a���𪺤s�u�C\n");
                set("unit", "�U");
                set("value", 50);       //�Ѧһ��欰�^�_�I���`�M���H5
                set("heal_mp",25);      //�i�H�O"heal_hp"�άO"heal_mp",
                set("heal_body",10);    //"heal_head" ,"heal_body"
                set("heal_head",7);    //"heal_hand" ,"heal_foot"�]�i�H����.
             set("heal_hand",5);
                set("heal_foot",3);  
                set("food_remaining", 5);
                //���ΰT�� eat_msg �i�H�� $N ���a, $n����.(�ж����|�ݨ�)
                set("eat_msg","$N���}�F�@�U$n, �����ܤF�@�f�A�̥̲����A���D���n�ܪ��C");
                //�ĪG�T�� eff_msg ���i��$N �� $n (�]���u�����a�|�ݨ�)
                set("eff_msg","�Aı�o��M�@�ѲM�D���𮧬y�L�����C");
        }
        setup();
}

