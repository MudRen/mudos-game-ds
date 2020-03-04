#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();
void create()
{
  set_name(HIC"�Q���ȴ�"NOR, ({"leviathan","_LEVIATHAN_"}) );
  set("long",@LONG
���j�����D�A�֦����C�@�몺�Q���A���ү몺��ҡA��e�b����½�u
�ɷ|�ް_�j���S�A�O�W�Ũ�ꪺ�������̡A�ڻ��e�|ŧ����A�ܩ�
�O���]���L�H����C
LONG
);
  set("gender", "����");  
  set("race", "beast");
  set("unit","��");
  set("age",2800);
  set("level",62);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",RED"  �]�~ "NOR); 
  set("limbs", ({ "�Y��", "����","�ݳ�","����","�I��"}) );
  set("verbs", ({ "bite"}) );
  set("Merits/bar",8);
  set("Merits/bio",9);
  set("Merits/wit",5);
  set("Merits/tec",5);
  add("addition_damage",90);
  add("addition_armor",150);
  set_temp("apply/hit",20);
  set_temp("apply/dodge",10);
  set("chat_chance", 30);
  set("chat_msg", ({
  HIC"�Q���ȴ�"NOR"���t�a�b����½�˥X�S�A���餣�ɰ{�{�i���C\n",
     (: heal :),
  }));

  setup();
        if(random(100)>90) // 10%
                carry_object(__DIR__"eq/treasure-paper1");
        if(random(100)>90) // 10%
                carry_object(__DIR__"eq/treasure-paper2");
        if(random(100)>90) // 10%
                carry_object(__DIR__"eq/treasure-paper3");

  set_living_name("_NPC_LEVIATHAN_");
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(this_player()->query("level") > 25 && userp(this_player()) )
    this_object()->kill_ob(this_player());
  if(!random(3))
  {
    message_vision(HIC"�Q���ȴ�"HIR"��M�q������«�X�A�O$N�Ӥ��Τ����W�F��}�I�I\n\n"NOR,this_player() );
    this_player()->add_busy(random(2)+1);
  }
}

void heal()
{
  if(query("hp") > query("max_hp")) return;
  add("hp",250+random(120));
  return;
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(8))
  {
    me->start_busy(1);
    target->add_busy(2);
    message_vision("\n$N��M��J�����A�H�Y�b����½�͡A�޵o�]�ѷ��a��"HIC"�j���S"NOR"�I�I\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  else if(!random(7))
  {
    message_vision( "$N�i�}�����L�ƧQ�����j�L�C\n", me );
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  return 0;
}

void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIC"\n�j���S�����w�g���ʨ�o�̡A���e��h�u���ܤѪ������I�I\n"NOR,me);
  message_vision("\n�A�L�B�i�k�A�u�����E���O�Ө��o�@���I\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = random(250)+190;
      message_vision(HIC"$N�Q�ƤQ�������������A�y�ɤf�R�A��A���b�@��.... "HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      if( inv[i]->query_con() > 90 )
        inv[i]->add_busy(1);
      else if( inv[i]->query_con() > 75 )
        inv[i]->add_busy(2);
      else
        inv[i]->add_busy(3);
      COMBAT_D->report_status(inv[i]);
    }
/*
    else
    {
      message_vision(HIC"\n$N�Q�j�P�����y�����F .... \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
*/
  }
  me->start_busy(1);
  return;
}


void die()
{
  object ob,eqp;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  message("world:world1:vision",
       HIG"\n\t�i��@�q�j�G"+RED"�W�j�]�~  "HIC"�Q���ȴ�"HIW"  �Q�^�i��"+ob->name(1)+"�����F...\n\n"+NOR
       ,users());
  ob->add("popularity",7);      
  tell_object(ob,HIG"�A�o�� 7 �I�n��C"NOR);
  if( random(5000) )
    eqp=new(__DIR__"eq/leviathan-mask");
  else
    eqp=new(__DIR__"eq/leviathan-earring");
  eqp->move(this_object());
  ::die();
  return;
}
