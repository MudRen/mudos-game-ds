inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("���J����", ({ "pot" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("no_get",1);
		set("no_sac",1);
                set("long", "�@���J���o�������A�T�w�b�a�W�A���L���f�����H���ΡC\n");
                set("unit", "�y");
                set("value", 20);
                set("drink_msg", "$N�C�Y�b���J�����ܤF�X�f�E\n");
                  set("heal_ap",10+random(5));
                  set("heal_mp",10+random(5));
                  set("heal_hp",10+random(5));
                  set("water_remaining",300);          
        }
}

