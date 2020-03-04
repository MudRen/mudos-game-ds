#include <ansi.h>
#include <combat.h>
varargs int receive_damage(string type, int damage, object who);
inherit NPC;
inherit SSERVER;
void normal_ai();
void combat_ai();

void create()
{
  set_name("��V�D����" , ({ "hyuuga asaka","asaka" }) );
  set("long",@long
�j�ۤ@�������������A�������D�����֤֤k�A���O�o�y�W�o�S���P��
�k�ĩ����Ӧ����¯u�����A�ϦӬO�@�ؤ[�g�ɮ᪺��ݪ��A���R�M
�A���y���t�W�@��ӤM���H�@�����H�˪񪺷Pı�C
long
);
  create_family( HIC "�X���y" NOR ,2,"�̤l");
  set("level",40);
  set("race","�H��");
  set("age",20);
  set("title",HIC"�X���y"NOR);
  set("class1","�X���y");
  set("gender","�k��");
  set("asaka",1);
  set("apeman-enemy",1);
  set("str",80);
  set("con",90);
  set("int",55);
  set("dex",71);
  set_temp("apply/hit",40);
  set_temp("apply/dodge",40);
  set_skill("blade", 90);
  set_skill("sword", 90);
  set_skill("parry", 90);
  set_skill("dodge", 90);
  set_skill("unarmed",80);
  set("addition_damage",30);
  set("addition_armor",120);
  set("talk_reply","�z�n�C");
  set("inquiry/��t�D��","���I���O�ڤ��˪��W�r�A���ڧڤw���O�o�L�������F�C\n");
  set("inquiry/���H","���l�̪��H���o�˺٩I�ڤ��ˡAť���O�]���L���M�k�X���J�ơC\n");
  set("inquiry/�h�͡D�P��","�h�ͨ����ۤp���i�ڪ��j�A��������˪��Ʊ��L�l�פ����C\n");
  set("inquiry/�h�͡D���ӭ�","�ӭ��O�ڱq�p��j������A�]�O���R�M�k�����C\n");
  set("inquiry/�X���y","���O���˦۳Ъ��M�k�A�ڥu�����@�G�C\n");
  set("chat_chance", 50);
  set("chat_msg",({
     (: normal_ai() :),
     }) );
  set("chat_chance_combat",100);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  setup();
  set_living_name("_NPC_ASAKA_");
  carry_object(__DIR__"eq/chrysoprase-earring")->wear();
  carry_object(__DIR__"eq/kiku-ichimonji-katana")->wield();
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
  carry_object(__DIR__"eq/genki-pill");
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("tengu") ) this_object()->kill_ob(this_player());
  if( this_player()->query("apeman") ) this_object()->kill_ob(this_player());
/*
  if( this_player()==this_object()->query_temp("last_opponent") )
  {
    if( this_object()->is_busy() ) return;
    message_vision(HIG"(�w������)"NOR"��V�D�����@�ө}��½��A¶��$N�I���ӱ��⤣�ΡI�I\n"NOR,this_player() );
    this_player()->add_busy(random(2)+1);
  }
*/
}

int accept_object(object who,object ob)
{
  object obj,letter;
  obj=this_object();

  if(obj->is_busy() || obj->is_fighting())
  {
    command("whisper "+who->query("id")+" �ڨS�šA�O�ӷЧڡC\n");
    return 0;
  }
  if(ob->query("id") == "hoshiakari's letter")
  {
    message_vision("$N������V�D�����@�� "+ob->query("name")+"�C\n",who);
    command("hmm");
    message_vision("��V�D�������_�H�J�Ӧa�ݤF�@�M�A���ؤ��ѱo�R���\\���C\n",who);
    if( who->query("level") <30 )
    {
      command("say �P�§A���ǹF�A�ڷ|�ۤv�Q�k�l����˪��C");
      return 1;
    }
    command("say �A�i���ڤ��˲{�b��B�H");
    who->set_temp("go_with_asaka",1);
    destruct(ob);
    return 1;
  }
  return 0;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if( (strsrch(str,"��") != -1) && (me->query_temp("go_with_asaka") == 1) )
  {
    command("say �бa���H��A���ڨ����ˤ@���I");
    call_out("do_follow",1,me);
    me->delete_temp("go_with_asaka");
    return;
  }
  return;
}

int do_follow(object me)
{
  this_object()->set_leader(me);
  call_out("no_follow",300);
//  command("follow "+me->query("id"));
  return 1;
}

int no_follow()
{
  command("say ���d���o�[�٨S��H����F�I");
  this_object()->set_leader(0);
  return 1;
}

void normal_ai()
{
  object me,z;
  me = this_object();
  if( me->is_busy() ) return;

  if( !me->query_temp("weapon") && objectp(z=present("katana",me)) )
    command("wield katana");
  if( me->query("hp") + 1500 < me->query("max_hp") )
    command("eat pill");
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
    command("wield katana");
  if( me->query("hp") + 1500 < me->query("max_hp") )
    command("eat pill");
  if(!random(15))
  {
    me->start_busy(1);
    message_vision(HIR"$N���@�_�A�������n��$n�C\n"NOR,me,target );
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
    damage/=4;
    message_vision(HIW"\n$N�H�X�n�����q�A�I�I�׶}�F���������C\n" NOR,this_object());
  }
    if(damage<1) damage = 1;
  if(objectp(who) )
    ::receive_damage(type,damage,who);
  else
    ::receive_damage(type,damage,who);
  return damage;
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
