inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("�o��������ü��", ({ "greasy meat soup" , "soup" }) );
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�J�o����F���I����ü���A������F
�h�[����ü�������O�o�{�C\n");
                set("drink_msg","$N���ۻ�l�A�V�O����U�o�J�o����F���I����ü�C\n");
                set("eff_msg","
�@�����ߪ��Pı�q�G�̽ĤF�W�ӡA�A�V�O������o
�طPı�A�b�@�q�ɶ����V�O��A���M��O��_�F�I
�A�����w���������m�|���A���J��d�G���B�ҡC\n");
                set("unit","�J");
                    set("value",300);
           set("heal_hp",5);
                set("water_remaining",2);
        }
     setup();
}

