#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("���Z�h�M", ({ "wu-shi blade" , "blade" }) );
        set_weight(5000);
        setup_blade( 3 , 8, 90, 0);

        if( !clonep() ) {
                set("wield_as",({ "blade" }) );
                set("unit", "��");
                set("value", 4000 );
                set("rigidity", 120);
                set("long", "�o�O�@����O�ت��Z�h�M�A�M�W���`�U�Q�A�ݪ��X�ӱ��ˤO���C�C\n");
       }
        set("apply_weapon/blade", ([
                        "str" : 1,
                    ]) );
        setup();
}

