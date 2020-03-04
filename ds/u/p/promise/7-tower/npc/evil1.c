#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();
void create()
{
  set_name(HIC"�m��"NOR, ({"fei xuan","xuan"}) );
  set("long",@LONG
�C���𤧤����k�ʤ��̡A�ժ����@�A�b�H�@���D�W�������̡A��ާ˱o
�����k�ʺX���۷��H�A���i�ơC
LONG
);
  set("gender", "�k��");  
  set("race", "�H��");
  set("age",20);
  set("level",47);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",HIM"�����V"NOR); 
  set("Merits/bar",10);
  set("Merits/bio",10);
  set("Merits/wit",1);
  set("Merits/tec",10);
  add("addition_damage",130);
  add("addition_armor",200);
  set("max_hp",10000);
  set("chat_chance", 30);
  set("chat_msg", ({
  HIM"�m��"HIW"���t�����w����X�媺����...."HIR"(+300)\n"NOR,
     (: heal :),
  }));
        set("chat_chance_combat",80);
        set("chat_msg_combat",({
  (: command("do wield whip") :),
  (: command("do wield whip") :),
  (: command("do wield whip") :),
  (: command("do wield whip") :),
  (: command("do wield whip") :),
  (: command("do wield whip") :),
  (: command("do wield whip") :),
  (: command("do wield whip") :),

}));

    setup();
  carry_object(__DIR__"eq/eq1")->wear();
  carry_object(__DIR__"wp/wp1")->wield();
 }

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;

  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(this_player()->query("level") > 40 && userp(this_player()) )
    this_object()->kill_ob(this_player());
}

void heal()
{
  if(query("hp") > query("max_hp")) return;
  add("hp",300);
  return;
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7))
  {
    me->start_busy(1);
    target->add_busy(2);
    message_vision("\n$N"HIR"���񤭻�B�k�A�W�իݵo�A�����l�b�@�l�W�A�ϥX��H�@���I�I\n"NOR,me);
    call_out("do_super",2,me);
    return 1;

}
 
}
void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIC"\n�E�D�g���������몺�����A�D�Dŧ���A���n�`�I�I\n"NOR,me);
  message_vision(HIG"\n�A�L�k���}��������A�u���q�q���ݵۼƹD�@��ŧ���I�I\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = 250+random(200);
      message_vision(HIR"$N�Q�L������������A�ݦ��D�`�h�W�A�����Y�����ˮ` "HIR"("+damage+")\n\n"NOR,inv[i]);
      message_vision(HIW"�u���ĤH�������F�A�ϥX����H���@�k�׬��I�I\n"NOR,me);
      inv[i]->receive_damage("hp", damage, me);
      call_out("do_super2",2,me);      COMBAT_D->report_status(inv[i]);
    }
    else
    {
      message_vision(HIC"\n$N�ϥX���ժ����\\�A���}�������I�I\n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(1);
  return;
} 

void do_super2(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;
  message_vision(HIW"\n�u��$N"HIW"�A���ծ����O�A�C�C����_�H���������C\n\n"NOR,me);
  message_vision(HIW"\n�٨����A�j�a�ܦ�A�D�D�����@��G���F�����........\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = 400+random(100);
      message_vision("\n"HIC"�m�y"NOR+CYN"�R�R���q���ۡG"HIW"�᳷�@�B��...................�I�I�I\n\n"NOR,me);   
      message_vision(HIR"$N�A������L��������üY�A�y����e�����Y�����ˮ`.....�C "HIY"("+damage+")\n\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      
      COMBAT_D->report_status(inv[i]);
    }
    else
    {
      message_vision(HIC"\n$N�ϥX���ժ����\\�A���}�������I�I\n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(1);
  return;
}
void die()
{
  object ob,env;
   int temp;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  env = environment(ob);
  temp = NATURE_D->which_world(env);
  message("world:world1:vision", "\n\t"HIW"�N�b" +NATURE_D->game_time(temp)+"       "NOR+CYN"\n\n\t�C����s��....�a��C����Ĥ@�h "HIM"�m�� "HIW"�Ѧb"HIY+ob->query("name")+HIW"��W\n\n"+NOR
       ,users());
  ob->add("popularity",5);      
  tell_object(ob,HIY"�����F�����A�򯪤j�}�k�����A���I�n��H���ż��C"NOR);
    switch( random(50) )

  {
    case  0..25: new(__DIR__"obj/book")->move(ob);
          break;
    case  26..50: new(__DIR__"obj/gold-box")->move(this_object());

          break;
    }
  
   ::die();
  return;
}

