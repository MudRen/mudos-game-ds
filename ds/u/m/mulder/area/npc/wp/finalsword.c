#include <weapon.h>
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
inherit SWORD;
void create()
{      
	set_name(HIB"�׵����C"NOR,({"final sword","sword"}) );
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long",HIG"�o�O�@��׵��t�C�C\n"NOR);
        set("value",100000);
        set("rigidity",10000);
        set("limit_str",10);
        set("limit_con",10);
        set("limit_dex",10);
        set("limit_int",10);
        set("weapon_prop/hit",100);
        set("material", "blacksteel");
        set("wield_msg",HIR"$N�{�Ť@���A�ѤW���Ӥ@��t�C�A$N�ⴤ$n�C\n"NOR);
        set("unwield_msg", RED"$N�N�⤤��$n���ѤW�@�ߡA$n�L�v�L�ܤF�C\n");
        init_sword(1000000);
        setup();
        }
}
void attack(object me,object victim)
{
	int damage,hp,maxhp,mp;

  me=this_player();
  hp=me->query("hp");
  maxhp=me->query("max_hp");
  mp=me->query("mp");
 if ( hp < maxhp/2 )
 { 
   damage=100000+random(10) *(hp+mp);
  message_vision(HIR" �׵����C�l���F�Ҧ��O�q�A��X�W�Ť@���I�I�I
  �y��$N"+damage+"�I���ˮ`�I�I�I�I\n"NOR,victim); 
  victim->receive_damage("hp", damage, me );
 me->set("hp",1);
 me->set("mp",0);
 return;    
 }
}
void init()
{
  add_action("do_berserk","berserk");
}
int do_berserk(string arg)
{
 object me, target;

 int skill, cost;
 
 me=this_player();
 if(!me) return 0;
 if(me->start_busy()) return notify_fail("�A�ʧ@�٨S����..\n");
 if(me->query_temp("berserk")) return notify_fail("�A����s��I�i�T�G.\n");
 if(!me->is_fighting())
        return notify_fail("�o�ӧޯ�u��b�԰��ɨϥΡC\n");
 if(arg)
 {
  target=present(arg, environment(me));
  if(!target) return notify_fail("�n��֬I�i�T�G??\n");
  if(!me->is_fighting(target)) return notify_fail("�o�ӧޯ�u���A�ثe���ĤH�ϥΡC\n");
 }
 else target = offensive_target(me);   
 if(!target) return notify_fail("�o�ӧޯ�u���A�ثe���ĤH�ϥΡC\n");
 skill=me->query_skill("berserk",1);
 cost = 25;
 if(me->query("mp") < cost) return notify_fail("�A�ثe����O���p�L�k�I�i�T�G\n");
 message_vision(HIR"\n$N��W���׵����C�|�ۥj�N�]�k���T�G�I...\n\n"NOR,me);
 skill/=8;
 me->set_temp("berserk",1);
 me->start_busy(2);
 me->add("mp",-cost);
 call_out("do_crazy",4,me,target,skill);
 call_out("do_clean",8,me);
 return 1;
}
int do_crazy(object me,object target,int times)
{
  int i;
  if(!me) return 0;
  if(target!=present(target->query("id"), environment(me)))
  {
    me->delete_temp("berserk");
    return notify_fail("�ؼЦ��G�����F�A�������d��..\n");
  }
  message_vision(HIY"\n��㶩�����ѤW��M�V$N�g�X�@�����u�I�I\n\n",me);
  for(i=0;i < times ;i++)
  COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_BERSERK); 
  COMBAT_D->report_status(target);   
  me->improve_skill("berserk",1+random(me->query_int()/10));
  return 1;
}

int do_clean(object me)
{
 if(!me) return 0;
 me->delete_temp("berserk");
 return 1;
}

int query_autoload() { return 1; }

