#include <ansi2.h>
#include <combat.h>
varargs int receive_damage(string type, int damage, object who);
inherit NPC;
inherit SSERVER;
void normal_ai();
void combat_ai();

void create()
{
  set_name("��t�D��" , ({ "akikawa asahi","asahi","master" }) );
  set("long",@long
�h�~�H�e�q�F��j���}�y�w�~�b�o�Ӥp�q�A�H�p�q�W�S�����M�ĦX��
�k�A�}�ХX�M�k���s�ҬɡA�W�����ХX���y�C�ѩ��M�k���g���H��
���U���t���A���s�W�ۥͬ��b�o���˪L���A���M�Y�v�w�g�ȥզ�����
�ݨӤ��M�����A�ר������~�~�����Ӻ�������C
long
);
  create_family( HIC "�X���y" NOR ,2,"�v�d");
  set("level",60);
  set("race","�H��");
  set("age",65);
  set("title",HIM"���H"NOR);
  set("class1","�X���y");
  set("gender","�k��");
  set("str",140);
  set("con",120);
  set("int",87);
  set("dex",100);
  set_temp("apply/hit",80);
  set_temp("apply/dodge",80);
  set_skill("blade", 100);
  set_skill("parry", 100);
  set_skill("block", 100);
  set_skill("dodge", 100);
  set_skill("unarmed",100);
  set_skill("shinin-ryuu-blade",100);
  set_skill("monkey-dodge",100);
  map_skill("blade","shinin-ryuu-blade");
  map_skill("dodge","monkey-dodge");
  set_temp("apply/armor",150);
  set("talk_reply","�A��q�L���L��o�̭ˤ]��²����C\n");
  set("inquiry/��V�D����","�������A�����D�o�{�b�L�o�p��A�����̪��ͬ��|��o����n�C\n");
  set("inquiry/��V�D���l","���D�D�D�D�D\n");
  set("inquiry/�Ѫ�","�����̳��ڽm�M�A�ͬ��ˤ]���L��C\n");
  set("inquiry/�s��","��H���O����F��H\n");
  set("chat_chance", 50);
  set("chat_msg",({
     (: normal_ai() :),
     }) );
  set("chat_chance_combat",100);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  setup();
  carry_object(__DIR__"eq/dragon-marking-waist")->wear();
  carry_object(__DIR__"eq/sakura-ranbu-katana")->wield();
}

void init()
{
  ::init();
  if( this_player()->query_temp("kill_black_tengu") )  {
    remove_call_out("give_pill");
    call_out("give_pill",0,this_player());
  }
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("asaka") ) call_out("speaking",0);

}

void normal_ai()
{
   object me;
  me = this_object();
  if( me->is_busy() ) return;

  if( !me->query_temp("weapon") )
  { 
    command("wield katana");
  }
  if( me->query("hp") + 300 < me->query("max_hp") )
  {
    me->start_busy(3);
    message_vision("\n$N"HIG"�q�h�����X�X���ĤY�A�@�f�Y�F�U�h�C\n\n"NOR,me);
    me->receive_heal("hp",300);
    return;
  }
  switch( random(30) )
  {
     case  0: 
           message_vision("$N���ʪ��M�H�ֱ����t�׺t�m�ۦ��A�C�Ӱʧ@�����a�j�j��աC\n",me);
           break;
     case  1:
           message_vision("$N�§A����V��@�M�A�j�P�����ϧA�t�I������}�C\n",me);
           break;
     case  2:
           message_vision("$N���۷����A�A�`�N��M�W���M���q���{�ʡI\n",me);
           break;
     default: break;
  }
  return;
}

void combat_ai()
{
  object me,target,z;
  me=this_object();
  target = offensive_target(me);
  if(!me) return;
  if(!target) return;
  if(me->is_busy()) return;
  if(!objectp(z=present("katana",me)) )  
  {
    message_vision("\n$N�q�y���ޥX�t�@��M�C\n"NOR,me);
    new(__DIR__"eq/ya-katana")->move(me);
  }
  if( objectp(z=present("katana",me)) &&  z->query_durable() < 0 )
  {
    message_vision("\n$N�N�M���Τ��@��C\n"NOR,me);
    destruct(z);
  }
  if( !me->query_temp("weapon") && objectp(z) )
  { 
    command("wield katana");
    return;
  }
  if( random(target->query_dex()) < 9)
  {
    me->start_busy(1);
    message_vision(HIM"\n$N��$n�ϥX"HBK"�v���N"HIM"�A$n�@�ɥ����L�k�ʼu�I\n\n"NOR, this_object(), target);
    target->add_busy(3);
    return;
  }
  else if( !random(8) )
  {
    me->start_busy(1);
    message_vision(HIW"$N���O�B�ण���A�ǳƨϥX�s���C\n"NOR,me,target );
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_BERSERK);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_BERSERK);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_BERSERK);
    return;
  }
  else if(!random(8))
  {
    me->start_busy(1);
    message_vision(HIR"$N�����M��$n�g�����}��C\n"NOR,me,target );
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return;
  }
  return;
}

void speaking()
{
  object me,ob1,ob2,env,boots;
  me=this_object();
  ob1=find_living("_NPC_ASAKA_");
  ob2=ob1->query_leader();
  env=environment(ob2);

  command("pat asaka");
  command("look asaka");
  command("say �A�O�����a�A�ڬݬݡA�����o��j�աC");
  command("say ���W�p�F�A�Ĥl�A�֥��i�h�����@�U�a�C");
  ob1->set_leader(0);
  if( env=environment(me) )
  {
    message_vision("$N��L���ӹ��$n���D�G�P�§A�����ڦh�~�Ӫ����@\n"
                  +"�A�ڳo���ӪF��ЧA���U�a�C\n"NOR,me,ob2);
    boots=new_ob(__DIR__"eq/kilin-boots");
    boots->move(me);
    command("give boots to "+ ob2->query("id") );
    return;
  }
  destruct(ob2);
  return;
} 
/*
// report too much �ק� by JS@DS
varargs int receive_damage(string type, int damage, object who)
{
  int val;
  if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
  if( type!="hp" && type!="mp" && type!="ap" )
      error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
  if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
  if(random(100)<20)
  {
    damage=0;
    message_vision(HIW"\n$N�H�ֱ������k�A�����w�{�����դ��~�C\n" NOR,this_object());
  }
  if(objectp(who) )
    ::receive_damage(type,damage,who);
  else
    ::receive_damage(type,damage,who);
  return damage;
}
*/
void give_pill(object ob)
{
  int i;
  message_vision("\n��t�D�����$N���D�G�դU�u�O��²��A�o�Ǥ��ĵ��A�i�i���l�C\n" NOR,ob);
  for(i=0;i<3;i++)
  {
    new(__DIR__"eq/ginseng-pill")->move(this_object());
    command("give pill to "+ ob->query("id") );
  }
  ob->delete_temp("kill_black_tengu");
  return;
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  message("world:world1:vision",
  HIC"\n\t�i�F��q�j�G"HIW"�����H���٪�"+HIG" �X���y�ФH "HIW"��t�D�� ���Ѧb"HIY+ob->name(1)+HIW"����A��b���H�m�H�C\n\n"+NOR
    ,users());
  ob->add("popularity",10);      
  tell_object(ob,HIG"�A�o�� 10 �I�n��C"NOR);
 ::die();
  return;
}


