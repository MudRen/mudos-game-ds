#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIM"��"+NOR+""+MAG+"�R�_"+NOR+""+HIM+"��"NOR, ({;
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O��R�C�Ъ��R�C...!\);
                set("material", "blacksteel");
        set("value",10000);
        }
        init_blade(40);
        set("wield_msg",MAG"$N�@��M$P���W�X�{��⤤...�C\n"NOR);

        set("unwield_msg",CYN"$N�N�⤤��$n��^�I���C\n"NOR);

        setup();
}

void attack(object me, object victim)
{
    int damage,def;

    ::attack();
    if(!me) return;
    if(!victim) return;

    if(me->query_skill("blade") > 50 && me->query_dex() > 20 && random(10)<3 )
    {
      message_vision(HIW "\n���D$N�⤤�ѻR�_�����_���, �@�Ѧ�𳺱q�ѻR�_�����g�X,;
      damage += me->query_skill("sword")+me->query_str()+random(30);
      def += victim->query_skill("parry")+victim->query_skill("dodge")+victim->;
      def = def/3;
      if(damage-def>0 && random(10)>5)
      {
        damage=damage+random((damage-def));
        message_vision(HIR "$N�{�����ΡD�D�D����騭�I�I\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
      }
      else message_vision(HIG "$N�j�ܤ@�n, �N�������촲, �|�P�����}�}�C\n"NOR,vic;
    }
    return;
}
