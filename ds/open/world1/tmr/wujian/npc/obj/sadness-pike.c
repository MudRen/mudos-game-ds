#include <weapon.h>
#include <ansi.h>
inherit SSERVER;
inherit FORK;

void create()
{
        set_name( HIC "�d�z�j" NOR,({"sadness howl pike", "pike"}) );
        set("long",@LONG
�F�Z�L�����[���j�������@�A���q���u���P��l���S�̩�j�}������
�A��ǻP��p��l��i�d��⤤�C�d�z�j�@�X�ʡA�|�o�X�_�Ѱʦa��
�d�z�]���A�v�T�H���ߴ��C���j��Ӥ����y����B�C
LONG
        );
        set_weight(4000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("value",8000);
                set("volume",3);
                set("limit_level",40);
                set("limit_skill",70);
        }
        set("weapon_prop/shield",10);
        set("weapon_prop/armor",10);
        set("weapon_prop/bar", -1);
        set("weapon_prop/sou", 1);
        init_fork(60);
        setup();        
}

void attack(object me, object victim)
{
    ::attack();
    if(!me) return;
    if(!victim) return;

    if( me->query_skill("sword") < 80 ) return;
    if( me->query_dex() < 50 ) return;
    if( random(100) < 80 ) return;      /* 20% ���S��o�ʲv */

        message_vision(HIB"�d�z�j�X�_�Ѱʦa���d�z�]���A$n"HIB"���ߴ��j���v�T�I�I\n" NOR, me, victim);
//        victim->receive_damage("hp", 10 + random(40), me);      /* 10~49 */
        victim->start_busy(1);
}

