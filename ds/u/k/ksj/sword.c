#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("�Ů�C", ({ "air sword", "sword" }));
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o��Ů�C�O�Q�ή�l�Ҿ��X�Ӫ��C�A�ѩ󤣬O����A�ҥH�u������@�q�u�ɶ��C\n");
                set("no_drop", 1);
                set("no_sac", 1);
                set("no_give", 1);
                set("no_get", 1);
                set("no_put", 1);
                set("no_sell", 1);
                set("volume",0);
                set("material", "steel");
        }
        init_sword(20);
// These properties are optional, if you don't set them, it will use the
// default values.


// The setup() is required.
        call_out("check_wield", 30);
        setup();
}

void check_wield()
{
        object me = environment(this_object());
        if( !this_object() || !me ) return;
        if( me->query_temp("weapon")!=this_object() )
        {
         tell_object(me,"�Ů�C�C�C���h�C�ΡA���������F�I\n");
         destruct(this_object());
        }
        call_out("check_wield", 35);
}
