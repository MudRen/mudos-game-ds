#include <ansi2.h>
#include <combat.h>
inherit NPC;
inherit SSERVER;
varargs int receive_damage(string type, int damage, object who);
void normal_ai();
void combat_ai();

void create()
{
  set_name(HBK"�¤Ѫ�"NOR, ({"black tengu","tengu","_BLACK_TENGU_"}) );
  set("long",@LONG
�Ѫ������̱j�̡A�]�O���Ѫ�������A�髬������@��Ѫ��j���A��
�ۯ¶ª���A�A���ⴧ�R�۩_�Ǫ��L�b�C
LONG
);
  set("race", "�H��");
  set("unit","��");
  set("age",150);
  set("attitude", "aggressive");
  set("evil",70);
  set("title",HIW"�Ѫ�����"NOR); 
  set("gender", "�k��" );
  set("level",60);
  set("int",86);
  set("con",140);
  set("str",120);
  set("dex",100);
  set_skill("unarmed",90);
  set_skill("blade",90);
  set_skill("sword",90);
  set_skill("dodge",100);
  set_skill("parry",80);
  set_temp("apply/hit",40);
  set_temp("apply/dodge",60);
  add("addition_armor",150);
  add("addition_shield",50);
  set("talk_reply","�����Ӧ��A�u�O���������I\n");
  set("inquiry/���H","�N�O��t�D�������Y�A�t�Y�b�n�誺�˪L�̡C\n");
  set("chat_chance", 80);
  set("chat_msg",({
     (: normal_ai() :),
     }) );
  set("chat_chance_combat",200);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  set("can_defend", 1);
  setup();
  set_living_name("_NPC_BLACK_TENGU_");
  carry_object(__DIR__"eq/hide-bone-katana")->wield();
  carry_object(__DIR__"eq/black-tengu-cloth")->wear();
  carry_object(__DIR__"eq/angry-mask")->wear();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("tengu-enemy") ) this_object()->kill_ob(this_player());
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
  if( this_player()==this_object()->query_temp("last_opponent") )
  {
    message_vision(HIG"(�w������)"HBK"�¤Ѫ�"HIW"�µ�$N�R�X�@�ΥշϡA$N�@�ɶ������L�k�����I�I\n"NOR,this_player() );
    this_player()->add_busy(random(2)+1);
  }
}

void normal_ai()
{
  object me,target,ob1,ob2,ob3,z;
  me = this_object();
  ob1=find_living("_NPC_PROTECT_TENGU1_");
  ob2=find_living("_NPC_PROTECT_TENGU2_");
  ob3=find_living("_NPC_PROTECT_TENGU3_");

  if(me->is_busy()) return;
  if( !me->query_temp("weapon") && objectp(z=present("katana",me)) )
  { 
    command("wield katana");
  }
  if( !me->query_temp("weapon") && objectp(z=present("sword",me)) )
  { 
    command("wield sword");
  }

  if( me->query("hp") + 300 < me->query("max_hp") )
  {
    message_vision("\n$N"HIG"���X���s�����ġA��b���W���ˤf�C\n\n"NOR,me);
    me->receive_heal("hp",300);
    me->start_busy(3);
    return;
  }

  switch( random(30) )
  {
     case  0: 
           message_vision("$N���D�G�n���O���H�����סA�ڦ��N��J�����F�C\n",me);
           break;
     case  1:
           message_vision("$N���D�G�i�몺���H�A�W���j�Ԥ����F�ڤ��֤�U�C\n",me);
           break;
     case  2:
           message_vision("$N�N�ۯݫe���ˬͻ��D�G���H���M�k�u�O�X���J�ơA�L�H��ġC\n",me);
           break;
     case  3:
           message_vision("$N�R�ʨ��᪺�¦����l�A���_�@�}�ۭ��C\n",me);
           break;
     case  4:
           if( objectp(ob1) || objectp(ob2) || objectp(ob3) )
           {
             message_vision("$N���"HIC"�u�@�Ѫ�"NOR"���D�G�S�ƤF�A�A�̤U�h�a�C\n",me);
             destruct(ob1);
             destruct(ob2);
             destruct(ob3);
           }
           break;
   }
  return;
}

void combat_ai()
{
  int hp,mp,ap,max_hp,max_mp,max_ap;
  object b,ob1,ob2,ob3,me,target;
  ob1=find_living("_NPC_PROTECT_TENGU1_");
  ob2=find_living("_NPC_PROTECT_TENGU2_");
  ob3=find_living("_NPC_PROTECT_TENGU3_");
  me=this_object();
  target = offensive_target(me);
  hp=this_object()->query("hp");
  mp=this_object()->query("mp");
  ap=this_object()->query("ap");
  max_hp=this_object()->query("max_hp");
  max_mp=this_object()->query("max_mp");
  max_ap=this_object()->query("max_ap");

  if( objectp(ob1) )
  {
    if(!environment(ob1) )  destruct(ob1);
  }
  else if( hp < (max_hp-2000) )
  {
    if(query_temp("wait_to_summon")) return;
    b=new(__DIR__"protect-tengu1" );
    b->move(environment(this_object()));
    message_vision("\n$N"HIW"�ѪŤ������ӤU�A���D�G�u�@�Ѫ��ѤW�I\n" NOR,b);
    set_temp("wait_to_summon",1);
    call_out("delay",20);
    return;
  }
  if( objectp(ob2) )
  {
    if(!environment(ob2) )  destruct(ob2);
  }
  else if( hp < (max_hp-2500) )
  {
    if(query_temp("wait_to_summon")) return;
    b=new(__DIR__"protect-tengu2" );
    b->move(environment(this_object()));
    message_vision("\n$N"HIW"�ѪŤ������ӤU�A���D�G�u�@�Ѫ��ѤW�I\n" NOR,b);
    set_temp("wait_to_summon",1);
    call_out("delay",20);
    return;
  }
  if( objectp(ob3) )
  {
    if(!environment(ob3) )  destruct(ob3);
  }
  else if( hp < (max_hp-3000) )
  {
    if(query_temp("wait_to_summon")) return;
    b=new(__DIR__"protect-tengu3" );
    b->move(environment(this_object()));
    message_vision("\n$N"HIW"�ѪŤ������ӤU�A���D�G�u�@�Ѫ��ѤW�I\n" NOR,b);
    set_temp("wait_to_summon",1);
    call_out("delay",20);
    return;
  }
  if(me->is_busy()) return;
  if( !me->query_temp("weapon") )
  { 
    command("wield katana");
    command("wield sword");
  }
  if(!random(12))
  {
    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
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
  if(random(100)<20)
  {
    damage=0;
    message_vision("\n$N"HIW"�Ƭ��@�η����A�{�}�F�o���������C\n" NOR,this_object());
  }
  if(objectp(who) )
    ::receive_damage(type,damage,who);
  else
    ::receive_damage(type,damage,who);
  return damage;
}

void delay()
{
  this_object()->delete_temp("wait_to_summon");
}

void die()
{
  object ob,ob1,ob2,ob3;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  ob1=find_living("_NPC_PROTECT_TENGU1_");
  ob2=find_living("_NPC_PROTECT_TENGU2_");
  ob3=find_living("_NPC_PROTECT_TENGU3_");
  if( objectp(ob1) && environment(ob1) )  destruct(ob1);
  if( objectp(ob2) && environment(ob2) )  destruct(ob2);
  if( objectp(ob3) && environment(ob3) )  destruct(ob3);
  message("world:world1:vision",
  HIM"\n\t�i���L�j�G"+HBK" �¤Ѫ� "HIW" ���b���i������"HIY+ob->name(1)+HIW"��U�A�q���������A��ߤѪ����I�ǤF�C\n\n"+NOR
    ,users());
  ob->add("popularity",7);      
  tell_object(ob,HIG"�A�o�� 7 �I�n��C"NOR);
  ob->set_temp("kill_black_tengu",1);
  ::die();
  return;
}
