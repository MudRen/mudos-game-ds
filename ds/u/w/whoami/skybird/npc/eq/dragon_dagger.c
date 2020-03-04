#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit DAGGER;

void create()
{
        set_name(HIC"�J���s"NOR, ({ "dragon dagger","dagger" }) );
        set_weight(2200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��"); 
                set("long", "�ǻ����o�O���R���٪����W�Z���A�P�_�ߦX�������P�A���_�ߤw������\n"
                            "��h�~�A�ѤU���o��J���s�b�P�ɤ����w�i�٤��A�A�J�Ӥ@�ݡA�b���L\n"
                            "�x�Ŧ�A�����a���H������A�O�@�ⷥ�����Ū��P���E\n");
                set("value", 23000);
                set("material", "steel");
                set("volume",1);
                set("limit_str",20);
                set("limit_dex",50);
                set("limit_level",40);
                set("limit_skill",60);
        }
        init_dagger(53);
        set("replica_ob", __DIR__"iron_dagger.c");
        set("weapon_prop/int", 3);
        set("weapon_prop/dex", 2);
        set("weapon_prop/str", 2);
        set("wield_msg", "$N��ⴤ��$n�A�K�ɤ@�}�H�𪽽��F��ޡC\n");
        set("unwield_msg", "$N�N�⤤��$n�äJ�h���C\n");
        setup();
}

void attack(object me,object victim)
{
        int i;
        object *enemy;
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(4)) return; 
        message_vision(HIC"$N�⤤���J���s��Q�X�@�ѴH��A���e�ĤH�L�@����A�Ҧ��B�W�E\n"NOR,me);
       
        enemy = me->query_enemy();
        for(i=0;i<sizeof(enemy);i++)
        { 
        enemy[i]->start_busy(random(3)); 
        enemy[i]->receive_damage("ap", 30+random(30), me);
        }
        return;
}


