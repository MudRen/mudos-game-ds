#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(GRN"�K��ɼC"NOR, ({ "ba-fang longsword","sword" }) );
        set_weight(12000);
        if( clonep() )
                 set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("material","crimsonsteel");
        set("limit_str",25);  
        set("limit_level",25); 
        set("long","�o�f�C�ָ�ج��A�`�W�O�۪Q��ۡA�^�����A�C�`�P�C�������y�C�z\n"
                   "�A��������ű���A���@�Ȼ��B��C\n");
        set("wield_msg",HIG"$N�w�w���q�j�몺�C�T����X$n"HIG"�A�@�}����{�{�C\n"NOR);

        set("unwield_msg", "$N�N�⤤��$n�������J�C�T�C\n");
        set("value",5000);
        } 
        set("weapon_prop/str", 1);
        set("weapon_prop/dex", 1);
        set_temp("sec_sword",1);
        init_sword(35, SECONDARY); 
        setup();
}

void attack(object me,object victim)
{
        object wp,ob = this_object();
        int x = me->query_skill("sword")/20+me->query_skill("force")/40,
           damage = x*50 + me->query_temp("apply/damage"),
           i;
        ::attack();
        if( !me->query_temp("secondary_weapon") ) return;
        wp=me->query_temp("secondary_weapon");
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return; 
        if(!wp->query_temp("sec_sword")) return;
      switch( random(10) ){
       case 0:
        message_vision(
        "$N"HIC"�x�_�C��諸���~�A�e�L�W�G�H�����A�A��G�Ѧa�ܲz���ʤH�u���A�Ť����ǹЦ��K\n"
        "�J�ϥۯ�Q�l�ޡA���y��«��$N"HIC"���W�y�A�b�����־��Ӧ��@�y�����A�C�W�Ƭ��@�I�C��\n"
        "�A���Y����·¶�̪������P���A�y�P�멹$n"HIC"���ض�����m�b�ӡC\n"NOR,ob,victim);    
        COMBAT_D->do_attack(me, victim, this_object(), random(5));
        COMBAT_D->report_statue(victim);
        COMBAT_D->do_attack(me, victim, this_object(), random(5));
        COMBAT_D->report_statue(victim);
        COMBAT_D->do_attack(me, victim, this_object(), random(5));
        COMBAT_D->report_statue(victim);
       break;
       case 1:
        message_vision( 
        HIG"\n�K��ɼC���a�C���j���A$N�b����o�ޤU�A��W�C�~�ɺ��A�V�L���Z��ŦӨӡA\n"
           "�K��ɼC�N�@�Ӥ@�ӥѤp�ܤj��������M�C���A�H�ۤK��ɼC�e���A�p�s�R�]����\n"
           "�q�p�ܤj��������$n"HIG"�e�ӡI\n"NOR,me,victim);
         if( victim->is_busy() || me->query_temp("apply/hit") > victim->query_temp("apply/dodge")
          && me->query("ap") > x ){
            message_vision("$N�Q"+chinese_number(x)+"�Ӯ��������A�˶դQ���Y���E",victim);
            if(victim->query_temp("apply/show_damage") || victim->query_temp("show_damage") )
            tell_object(victim,HIR"("+damage+")\n"NOR);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
            tell_object(me,HIR"("+damage+")\n"NOR);
            victim->receive_damage("hp",damage);
         } else if( me->query_skill("sword")+me->query_skill("force")
                  > victim->query_skill("parry")+victim->query_skill("force") ) {
            i = (victim->query_skill("force") - me->query("force"))/10 + 1;
        message_vision("$N�Φۨ��`�p�����\\���l�A�ƸѤF"+chinese_number(i)+"�Ӯ����E\n",victim);
        message_vision("���ѤU��"+chinese_number(x-i)+"�٬O�����F$N�A���M�y�����p���ˮ`�E",victim);
        if(victim->query_temp("apply/show_damage") || victim->query_temp("show_damage") )
        tell_object(victim,HIR"("+damage/i+")\n"NOR);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIR"("+damage/i+")\n"NOR);
        victim->receive_damage("hp",damage/i);
         } else {
            message_vision("$N���I�������F�����E\n",victim);
         }
         me->receive_damage("ap",x);
       break;
      }       
      return;
}

