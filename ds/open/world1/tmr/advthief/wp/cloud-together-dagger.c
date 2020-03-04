#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit F_UNIQUE;
inherit DAGGER;

void create()
{
          set_name(HIC"�K�足��"NOR,({"cloud-together dagger","dagger"}) );
          set("long", @LONG
�K�足���O�@����u���L���A�����F���A���Q�󨾦u�ɪ������t�סA
�঳�ļ��}��誺�����A�Υd�۹�誺�C�b�A�P�ɥ��b�׷i�Z���o��
�����ĥΡC
LONG
);
        set_weight(1800);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
              set("value", 40000);
              set("limit_level", 25);
              set("material", "blacksteel");
        }
        init_dagger(45);
        set("replica_ob", __DIR__"tian-que_dagger.c");
         set("class_only", "thief");
        set("weapon_prop/bio", 1);
        set("weapon_prop/wit", -1);
        set("weapon_prop/dex", 2);
          set("weapon_prop/str", -2);
        set("backstab_bonus", 30); //�ʤ���
        setup();        
}
 
void attack(object me,object victim)
{ 
        ::attack(); 
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;

        if(random(5)) return; // 1/5 �����v�S��
        message_vision( HIC "$N"HIC"�⤤���K�足�����M�Q�X�}�}�����A�N$n"HIC"�ιγ��A$n"HIC"�@�ɤ����⨬�L���I�I \n"NOR,me,victim);
        victim->start_busy(2);
        return; 
} 

