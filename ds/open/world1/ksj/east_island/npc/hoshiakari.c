#include <ansi.h>
#include <combat.h>
varargs int receive_damage(string type, int damage, object who);
inherit NPC;
inherit SSERVER;
void normal_ai();
void combat_ai();
object master=this_object();

void create()
{
  set_name("�h�͡D�P��" , ({ "yagyuu hoshiakari","hoshiakari","master" }) );
  set("long",@long
�s���y���v�d�A�O�@��M�N����A�{��ܤM�N�F��X���J�ƪ��ҬɡA
�~��ݰ_�Ӯ�t�a���B������ġA�L�����b�o�̫��ɧ̤l���M�N�C
long
);
  create_family( HIC "�s���y" NOR ,2,"�v�d");
  set("level",47);
  set("race","�H��");
  set("age",43);
  set("title",HIG"�s���y"NOR);
  set("adv_class",1);
  set("class1","�s���y");
  set("gender","�k��");
  set("apeman_enemy",1);
  set("tengu_enemy",1);
  // �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
  // �ӥB�|�����`�M�n��n���� 20                  by shengsan
  //set("guild_gifts",({2,4,9,5}));
  set("str",110);
  set("con",126);
  set("int",53);
  set("dex",90);
  set_temp("apply/hit",60);
  set_temp("apply/dodge",60);
  //set("guild_skills",([
  //       "dodge" : ({120,3,70}),
  //       "parry" : ({130,2,60}),
  //       "sword" : ({130,3,70}),
  //       "godsword" : ({140,2,80}),
  //       "meditate" : ({120,3,80}),
  //       "mirage-steps" : ({140,3,80}),
  //       ])  );
  //set("guild_spells",([
  //       "god-fire" : ({130,3,90}),
  //       "god-benison":({170,2,50}),
  //       "summon_ghost" : ({130,3,90}),
  //         ]) );
  set_skill("shinin-ryuu-blade",100);
  //set_skill("parry_attack", 100);
  set_skill("blade", 100);
  set_skill("sword", 100);
  set_skill("parry", 100);
  set_skill("dodge",100);
  set_skill("unarmed",90);
  set_skill("monkey-dodge",100);
  map_skill("blade","shinin-ryuu-blade");
  map_skill("dodge","monkey-dodge");
  set("addition_damage",65);
  set("addition_armor",120);
//  set("no_check_class",1);
  set("talk_reply","�A����������n�i�D�ڶ�(say)�H");
  set("inquiry/���H","�N�O��t�D���A��~�Y���O�L���h�Ѫ��A�]�N�S�����Ѫ����l�F�C\n");
  set("inquiry/��V�D���l","���A��~�@���~�|�`���F�o�A�ڥu�༾�i�������j�Ӱ������v�C\n");
  set("inquiry/�Ѫ�","�Ѫ��E�����L���A�դO�j�j�A�@���O���������~�C\n");
  set("chat_chance", 50);
  set("chat_msg",({
     (: normal_ai() :),
     }) );
  set("chat_chance_combat",100);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  setup();
  carry_object(__DIR__"eq/silver-waist")->wear();
  carry_object(__DIR__"eq/shouugan-katana")->wield();
  carry_object(__DIR__"eq/armor-design-page");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
}

void init()
{
  ::init();
  if( this_player()->query_temp("kill_cat") )  {
  remove_call_out("give_pill");
  call_out("give_pill",0,this_player());
  }
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("tengu") ) this_object()->kill_ob(this_player());
  if( this_player()->query("apeman") ) this_object()->kill_ob(this_player());
}

void relay_say(object me, string str)
{
  object letter,ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if( strsrch(str,"�D��") != -1 )
  {
    command("say �A���D���a�s�檺�D���O�֡H�֧i�D�ڡI");
    me->set_temp("autarou_quest",1);
    return;
  }
  if( (strsrch(str,"�ߧ�") != -1) && (me->query_temp("autarou_quest") == 1) )
 {
    command("say ��Ӧp���I�A�i�@�N���������F�o�Ӥj�`�H");
    me->set_temp("autarou_quest",2);
    return;
  }
  if( (strsrch(str,"�@�N") != -1) && (me->query_temp("autarou_quest") == 2) )
  {
    if(ob->query_temp("autarou_ready"))
    {
      command("say �z�u�O�L�q�߸z�I���ݱz�������`�C");
      me->delete_temp("autarou_quest");
    }
    else
    {
      command("say �z�u�O�L�q�߸z�I�ڷ|�q���ڨ��U�A�Q��ߧ��C");
      me->set_temp("go_with_autarou",1);
      me->delete_temp("autarou_quest");
      ob->set_temp("autarou_ready",1);
      call_out("delay_quest1",1200);
    }
    return;
  }
  if( (strsrch(str,"�����") != -1) && (ob->query_temp("give_letter") == 0) )
 {
    command("say �಴�w�g�֢����~�աA�]�ӦV���������M���F�C");
    command("say ���_�ӧ�����䪹�A�A�@�N���ڶܡH");
    me->set_temp("asaka_quest",1);
    return;
  }
  if( (strsrch(str,"�@�N") != -1) && (me->query_temp("asaka_quest") == 1) )
  {
    if(ob->query_temp("asaka_ready"))
    {
      command("say ��A�ڬ��٬O�A�L�X�ѧa�C");
      me->delete_temp("asaka_quest");
    }
    else
    {
      command("say �n�A�o�ʫH�N�ЧA���������a�C");
      letter=new_ob(__DIR__"eq/letter");
      letter->move(ob);
      command("give letter to "+ me->query("id") );
      ob->set_temp("asaka_ready",1);
      me->delete_temp("asaka_quest");
      call_out("delay_quest2",1200);
    }
    return;
  }
  return;
}

void normal_ai()
{
  object me,target,ob1,ob2,ob3,z;
  me = this_object();
  if( !me->query_temp("weapon") && objectp(z=present("katana",me)) )
  { 
    command("wield katana");
  }
  if( me->query("hp") + 1500 < me->query("max_hp") )
  {
    command("eat pill");
  }
  switch( random(15) )
  {
     case  0: 
           message_vision("$N�Ĥf�𻡹D�G����o��h�~�F�A������٬O�������h�C\n",me);
           break;
     case  1:
           message_vision("$N�ۻy�D�G���H���M�N�u�O�O�H���H�Q���A�쩳�L�O���m�����O�H\n",me);
           break;
     case  2:
           message_vision("$N�ۻy�D�G�����]���j�F�A�]�\\�ӱN"HIW"�����"NOR"�@�ӤF���D�D\n",me);
           break;
     case  3:
           message_vision("$N�M��D�G�s�檺��ʦ��G�g�L���e�A���O"HIW"�D��"NOR"�O�֩O�H\n",me);
           break;
     case  4:
           message_vision("$N�ۻy�D�G�s�檺��ʦ��G�g�L���e�A���O"HIW"�D��"NOR"�O�֩O�H\n",me);
           break;
  }
  return;
}

void combat_ai()
{
  object me,target,z;
  me=this_object();
  target = offensive_target(me);
  if(!me) return;
  if(me->is_busy()) return;
  if( !me->query_temp("weapon") && objectp(z=present("katana",me)) )
  { 
    command("wield katana");
  }
  if( me->query("hp") + 1500 < me->query("max_hp") )
  {
    command("eat pill");
  }
  if(!random(4))
  {
    message_vision(HIR"$N�j�s�@�n�A�������E��O�C\n"NOR, this_object() );
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return;
  }
  return;
}

varargs int receive_damage(string type, int damage, object who)
{
  int val;
  if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
  if( type!="hp" && type!="mp" && type!="ap" )
      error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
  if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
  if(random(100)<30)
  {
    damage=0;
    message_vision(HIW"\n$N���ΤۤƬ��ƭӤۼv�A�{�}�F�����C\n" NOR,this_object());
  }
  if(objectp(who) )
    ::receive_damage(type,damage,who);
  else
    ::receive_damage(type,damage,who);
  return damage;
}

void delay_quest1()
{
  this_object()->delete_temp("autarou_ready");
}

void delay_quest2()
{
  this_object()->delete_temp("asaka_ready");
}
void give_pill(object ob)
{
  int i;
  message_vision("\n�h�͡D�P�����$N���D�G�z�u�O�j�^���A�ڳo�̦��Ƕ��ĵ��A�ɨ��C\n" NOR,ob);
  for(i=0;i<6;i++)
  {
    new(__DIR__"eq/genki-pill")->move(this_object());
    command("give pill to "+ ob->query("id") );
  }
  ob->delete_temp("kill_cat");
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
  HIC"\n\t�i�F��q�j�G"+HIG" �s���y���v�d "HIW"�h�͡D�P�� �Ѧb"HIY+ob->name(1)+HIW"����A�ް_�@�}�̰ʡC\n\n"+NOR
    ,users());
  ob->add("popularity",3);      
  tell_object(ob,HIG"�A�o�� 3 �I�n��C"NOR);
  ::die();
  return;
}


