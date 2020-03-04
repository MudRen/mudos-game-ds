// �쬰 MD �� mob, �]�w�PDS ���P, �ФŰѦ�
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
 set_name(HIM"�کZ���C"NOR,({"oten sword","sword"}));
 set_weight(39180);
 set("value",20230);
 if( clonep() )
  set_default_object(__FILE__);
 else {
  set("unit","��");
  set("long"," �·t�C�h �کZ�N�䲦�ͤO�q�ʦL�b�o��C����, �S�W[���K�C]�C�o��C�W��"
          +"\n���F�j��, �}�}������G�n�N�A��������G���T, �ǻ��u���A��N��ϥ����O"
          +"\n�q�ѩ�X��.\n");
  set("material","steel");
  set("sword",37);
 }
 init_sword(30,TWO_HANDED);
 //set("weapon_prop/damage",820+random(50));
 set("wield_msg",HIC"$N�q�ӤW��X$n"HIC", ���M$N���I��X�{�@�ӥ��j���¼v!!\n"NOR);
 set("unwield_msg","�@�}�¼v�q$N�����W�V�W«��, $N�N$n���^�I�W���C�T�C\n");
 setup();
  set("weapon_prop/damage",query("sword")*2);
  set("weapon_prop/hit",query("sword")*2 );
  set("weapon_prop/attack",(int)query("sword")/3);
  set("weapon_prop/parry",(int)query("sword")/5);
}

int fail_eq(object me)
{
 string wname;
 int dam;
 wname=this_object()->query("name");
if(!me) return 0;
 if(me->query("int") < 20+random(20) )
 {
  message_vision("\n"+wname+HIY"�o�X�@�}�C�z: $N����O�٤�������X�ϧھ԰�!!\n\n"NOR,me);
  message_vision(wname+HIR"�@�P����ʤF�@�U!! $N�Q�_�ˤF!!"NOR,me);
  dam=random(200);
  me->receive_damage("hp",dam);
  tell_object(me,"("HIR+dam+NOR")\n");
  message_vision("\n",me);
  return 1;
 }
 return 0;
}

void attack(object me,object victim)
{
 int lck,lv,vlck;
 int damage;

if(!me || !victim) return; 

 vlck=victim->query("level");
 if(random(vlck+20) < random(200))
 {
  message_vision(HIR"\n  �@      �ܡ�ڡ�㫢�㫢��㫢��㫢����[m\n"NOR,me);
  message_vision(HIC"\n$N�������M�ۤƬ��@�W������C, �M�b�@�ǯ��s�W��[1;34m�¦�Z�h!!![m\n"NOR,me);
  message_vision("[1;30m$N�ƨ���[1;34m�¦�Z�h[1;30m�}�l�C�C���"+victim->query("name")+"[1;30m�����[�t....\n\n\n[m"NOR,me);
  me->start_busy(2);
  call_out("attack2",3,me,victim);
  return;
 }
 return;
}

int attack2(object me,object victim)
{
 object link_ob;
 int lck,lv1,lv2,hhp,blood;
 int damage;

 if(!me || !victim) return 0; //by pudon

 lv1=me->query("level");
 if(!victim || victim->query("hp")<1)
 {
   message_vision(HIB"�¼v�䤣����K�����^��F$N"HIB"�����W.\n"NOR,me);
  return 1;
 }
 lv2=victim->query("level");
 lck=victim->query("level");
 if(random(lck) > random(me->query("level")*3) )
 {
 message_vision("\n[1;34m�¦�Z�h[1;31m�����n�X����[m!!  [1;37m�����ĦV$n....\n[m",me,victim);
 message_vision(HIW"\n�u���·t��[1;5;37m�@�D�{��[m.. $n"HIW"�Q���T�V�����L�F�o�P�R���@��!!\n"NOR,me,victim);
 return 1;
 }
  damage=me->query("int")*2;
  damage+=me->query("con");
  damage+=me->query("str");
  damage+=me->query("dex")*2;
  if(userp(victim)) damage =damage/4 ; else damage+=random(lv2*10);
  damage+=random(lv1*10);
  damage-=victim->query_temp("apply/armor");
  if(userp(victim)) hhp=victim->query("hp")/10; else hhp=victim->query("hp")/45;
  if(hhp>damage) damage=hhp;
  if(victim->query("hp")<damage) 
  {
   set_temp("upgrade",3);
  } else
  {
   if( random( me->query("level") + victim->query("level") )  > victim->query("level") )
    set_temp("upgrade",1);
  }
  message_vision("\n\n[1;34m�¦�Z�h[1;31m�����n�X����[m!!  [1;37m�����ĦV$n....\n[m",me,victim);
  message_vision("\n�u���·t��[1;5;37m�@�D�{��[m..   $n���W"HIR"�A��p�u����Q�X!!"HIG"("HIR+damage+HIG")\n\n\n"NOR,me,victim);
  victim->receive_damage("hp",damage,me);
  if(query_temp("upgrade"))
  {
   blood=query_temp("upgrade")+random(3);
   if(query("weapon_prop/damage")<65)
   {
    me->add_temp("apply/damage",blood);
    add("weapon_prop/damage",blood);
    me->add_temp("apply/hit",blood);
    add("weapon_prop/hit",blood);
   }
   message_vision(HIR"$N"HIR"�⤤��"HIM"�کZ���C"HIR"�l���F�ĤH���A��, ���𪽽Ķ��]!!\n"NOR,me);
   delete_temp("upgrade");
  }
  return 1;
}
