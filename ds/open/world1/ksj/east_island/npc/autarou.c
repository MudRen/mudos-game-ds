#include <ansi.h>
#include <combat.h>
#include <path.h>
varargs int receive_damage(string type, int damage, object who);
inherit NPC;
inherit SSERVER;
void normal_ai();
void combat_ai();

void create()
{
  set_name("�h�͡D���ӭ�" , ({ "yagyuu autarou","autarou" }) );
  set("long",@long
�h�͡D�P�����W�l�A�ثe����������ê������A�ͩʨIí�A�s���y�M
�N�۷���m�A���@�O���}�p�q��j���h�C���C
long
);
  create_family( HIC "�s���y" NOR ,2,"�̤l");
  set("level",40);
  set("race","�H��");
  set("age",21);
  set("title",HIG"�s���y"NOR);
  set("class1","�s���y");
  set("gender","�k��");
  set("apeman-enemy",1);
  set("tengu-enemy",1);
  set("str",100);
  set("con",100);
  set("int",40);
  set("dex",56);
  set_temp("apply/hit",30);
  set_temp("apply/dodge",30);
  set_skill("blade", 80);
  set_skill("sword", 80);
  set_skill("parry", 80);
  set_skill("dodge", 80);
  set_skill("unarmed",70);
  set_skill("shinin-ryuu-blade",70);
  set_skill("monkey-dodge",70);
  set("addition_damage",35);
  set("addition_armor",90);
  set("talk_reply","�z�n�A�z�O�~�a�Ӫ��a�A�_��N�O�����ˤF�A�i�O�_�I�i�J���C");
  set("inquiry/�s��","ť�����ӵ�L���b�t�a���X�����ˡA�]�\\�L���D�s��O�־ޱ����C\n");
  set("inquiry/������","�����˸̸g�`���s�榨�s�X�S�A�w�g�����֤H���b�˪L���F�C\n");
  set("inquiry/���H","ť���H�e�O�L���h�Ѫ��A�����D�L�O�_���b�@�C\n");
  set("chat_chance", 50);
  set("chat_msg",({
     (: normal_ai() :),
     }) );
  set("chat_chance_combat",100);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  setup();
  map_skill("dodge","monkey-dodge");
  map_skill("blade","shinin-ryuu-blade");
  carry_object(__DIR__"eq/observe-necklace")->wear();
  carry_object(__DIR__"eq/silver-gloves")->wear();
  carry_object(__DIR__"eq/bizen-chousen-katana")->wield();
  carry_object(__DIR__"eq/boots-design-page");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/silver-shield")->wear();
}

void init()
{
  ::init();
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query_temp("go_with_autarou")) call_out("do_follow",0,this_player());
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if( this_player()->query("apeman") ) this_object()->kill_ob(this_player());
  if( this_player()->query("tengu") ) this_object()->kill_ob(this_player());
/*
  if( this_player()==this_object()->query_temp("last_opponent") )
  {
    message_vision(HIG"(�w������)"NOR"�h�͡D���ӭ��Ƽľ����A�ƹD�M���ֳtŧ�V$N�I�I\n"NOR,this_player() );
    this_player()->add_busy(random(1)+1);
    this_player()->receive_damage("hp",random(50)+50,this_object());
  }
*/
}

void normal_ai()
{
  object me,target,ob1,ob2,ob3,leader,env,env2,z;
  me = this_object();
  leader=me->query_leader();
	if( !leader ) return; // alick
  env=environment(leader);
  env2=environment(me);

  if( !me->query_temp("weapon") && objectp(z=present("katana",me)) )
    command("wield katana");
  if( !me->query_skill_mapped("blade") )
    command("exert shinin-ryuu-blade");
  if( !me->query_skill_mapped("dodge") )
    command("exert monkey-dodge");       
  if( me->query("hp") + 1500 < me->query("max_hp") )
    command("eat pill");
  if( env2->query("king-room") ) call_out("speaking",0);
  if( (leader) && (env != environment(me)) && !random(10))  me->set_leader(0);
  switch( random(20) )
  {
     case  0: 
           message_vision("$N���D�G�u�Ʊ���I���������˪��s��A�ڴN�i�H�X�o��j���F�C\n",me);
           break;
     case  1:
           message_vision("$N���D�G�̪�s�泣�S����j�ʧ@�A�u�O�_�ǡC\n",me);
           break;
     case  2:
           message_vision("$N���D�Gť�����~�ӤH�i�J�찭���˭׽m�Z���A�Ʊ�L�̧O�J��s��s�C\n",me);
           break;
     case  3:
           message_vision("$N���D�G��j���h�@�w�ਣ�ѧ�h���Z�ǧ����C\n",me);
           break;
     case  4:
           message_vision("$N���D�Gť�������e�賓�����L�̦�ۤ@��M�N�W����\n"
            +"���H�A�i�O�V���ˤj�H���_�`�O�����Ať�������O���ˤj�H�q���H��\n"
            +"���ϥX���A�����D�Ӥ��Ӱݦo�C\n",me);
           break;
     case  5: 
           message_vision("$N���D�G���˦ѬO���n����d�X�s�檺���a�̡A�A�i�𰭤��ˡC\n",me);
           break;
     case  6: 
           message_vision("$N���D�G�W�^����j���R�F�������޵P�A��I�s��S�h�F���Ӻ�C\n",me);
           break;
  }
  return;
}

void speaking()
{
  command("hmm");
  command("say �ݨӿߧ��N�b�o�W���F�A�ѧڥ��W�h�����C");
  this_object()->move(__DIR__"../room57.c");
  return;
}

void combat_ai()
{
  object me,target,z,s;
  me=this_object();
  target = offensive_target(me);
  if(!me) return;
  if(me->is_busy()) return;
  if( !me->query_temp("weapon") && objectp(z=present("katana",me)) )
    command("wield katana");
  if(!objectp(s=present("silver shield",me)) && me->query("leader") )
  {
    new(__DIR__"eq/silver-shield")->move(me);
    command("wear shield");
  }
  if( me->query("hp") + 1500 < me->query("max_hp") )
    command("eat pill");
  if(!random(10))
    command("exert shinin-ryuu-blade");
  return;
}

varargs int receive_damage(string type, int damage, object who)
{
  int val;
  if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
  if( type!="hp" && type!="mp" && type!="ap" )
      error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
  if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
  if(random(100)<20)
  {
    damage/=3;
    message_vision(HIW"\n$N���ΤۤƬ���Ӥۼv�A�I�I�׶}�F���������C\n" NOR,this_object());
  }
  if(objectp(who) )
    ::receive_damage(type,damage,who);
  else
    ::receive_damage(type,damage,who);
  return damage;
}

int do_follow(object me)
{
  message_vision(HIY"\n$N�V���ӭ��D���Ʊ�����e�C\n" NOR,this_player());
  command("say �J�O�p���A�N���ڻP�A�P��a�C");
  this_object()->set_leader(me);
//  command("follow "+me->query("id"));
  me->delete_temp("go_with_autarou");
  call_out("no_follow",300);
  return 1;
}

int no_follow()
{
  command("say ����٤����ߧ��A��F�ڦۤv��a�C");
  this_object()->set_leader(0);
  return 1;
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
  ob->add("popularity",2);      
  tell_object(ob,HIG"�A�o�� 2 �I�n��C"NOR);
  ::die();
  return;
}
