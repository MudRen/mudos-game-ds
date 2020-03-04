#include <armor.h>
#include <combat.h>
#include <ansi.h>
inherit SSERVER;
inherit NECK;

void create()
{
set_name(HIW"NIKE"HIC"����"NOR,({"nike necklace","necklace"}));
set_weight(1800);
set("long","�o�O�Q���ܶ±M�Ϊ��@��C\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "iron");
set("unit", "��");
set("value",0);
set("no_sell",1);          
set("limit_con",1);
set("armor_prop/armor",12);
set("armor_prop/shield",12);
}
setup();
}

void init()
{
 add_action("do_help","help");
 add_action("do_berserk","berserk");
}

int do_help(string arg)
{
 if(arg=="necklace")
 {
  write(
   "\n�Ԥh���O����:\n"
  +"berserk: �ƨg����\n"
  );
  return 1;
 }
 return 0;
}

int do_berserk(string arg)
{
object me, target;
 int skill, cost;
 
 me=this_player();
 if(!me) return 0;
 if(me->start_busy()) return notify_fail("�A�ʧ@�٨S����..\n");
 if(me->query_temp("berserk")) return notify_fail("�A����s�򰵳o��E�P���ʧ@.\n");
 if(!me->is_fighting())
        return notify_fail("�o�ӧޯ�u��b�԰��ɨϥΡC\n");
 if(arg)
 {
  target=present(arg, environment(me));
  if(!target) return notify_fail("�n��֬I�i�ƨg����??\n");
  if(!me->is_fighting(target)) return notify_fail("�o�ӧޯ�u���A�ثe���ĤH�ϥΡC\n");
 }
 else target = offensive_target(me);    //����ƻ�inherit SSERVER;
 if(!target) return notify_fail("�o�ӧޯ�u���A�ثe���ĤH�ϥΡC\n");
 skill=me->query_skill("berserk",1);
 // if(skill<5) return notify_fail("�A���ޯ��٤������m\n");
 cost = 25;
 if(me->query("mp") < cost) return notify_fail("�A�ثe����O���p�L�k���p���@�P���ʧ@\n");
 message_vision(HIR"\n$N�Ⲵ�o��, �������J�F�ƨg���A...\n\n"NOR,me);
 skill/=8;
skill+=2;
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
  message_vision(HIW"\n���q���$N���Ѫ��S�}�l�o�g�F!!!\n\n"NOR,me);
  for(i=0;i < times ;i++)
  COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_BERSERK); 
  COMBAT_D->report_status(target);      //�[�W�o��i�H���target�����d���p
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


