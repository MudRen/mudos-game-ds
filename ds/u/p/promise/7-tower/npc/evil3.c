#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();
void create()
{
  set_name(WHT"�}��"NOR, ({"po ao","ao"}) );
  set("long",@LONG
�ݥL���ۤ@�Y�����Y�A�Y���W����]�r�A����P�ơA�����Q��
���H�~�M�O�ⶳ�x�궳���v�̡A������������H�ۤF�]�A���i
�Q�Ӫ����Ӧ��Ӥ����H�����L�h�C
LONG
);
  set("gender", "�k��");  
  set("race", "�H��");
  set("age",51);
  set("level",49);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",HIM"�d�~����"NOR); 
  set("Merits/bar",3);
  set("Merits/bio",3);
  set("Merits/wit",13);
  set("Merits/tec",14);
  add("addition_damage",110);
  add("addition_armor",200);
  set("max_hp",10800);
  set("chat_chance", 30);
  setup();
  //carry_object(__DIR__"eq/eq3")->wear();
  //carry_object(__DIR__"wp/wp3")->wield();
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

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7))
  {
    me->start_busy(1);
    target->add_busy(2);
    message_vision(HIC"\n$N"HIC"���ۤ⤤���]���A�ªŤ��e�F�ær�A�ϥX�|�ç��k�I�I\n"NOR,me);
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

  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = 100+random(20);
      message_vision(HIW"\n$N�Q�����F�Ĥ@�áy�]�D�L�E�z�A���O�ɥ��I�I......"HIR"("+damage+")\n\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      call_out("do_super2",1,me);
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
void do_super2(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = 100+random(10);
      message_vision(HIG"\n$N�Q�����F�ĤG�áy�U�]�����z�A��l�ɥ��I�I......"HIR"("+damage+")\n\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      call_out("do_super3",1,me);
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

void do_super3(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = 100+random(10);
      message_vision(HIY"\n$N�Q�����F�ĤT�áy�]�e�Z�L�z�A�����ɥ��I�I......"HIR"("+damage+")\n\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      call_out("do_super4",1,me);
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

void do_super4(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = 100+random(10);
      message_vision(HIR"$N�Q�����F�ĥ|�áy�]�D�ѤU�z�A�����I���_��,$N�����Y�����жˡI�I......"HIR"("+damage+")\n\n"NOR,inv[i]);
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
  message("world:world1:vision", "\n\t"HIW"�N�b" +NATURE_D->game_time(temp)+"       
  "NOR+CYN"\n\n\t�C����s��....�a��C����ĤT�h "WHT"�}�� "HIW"�Ѧb"HIY+ob->query("name")+HIW"��W\n\n"+NOR
       ,users());
  ob->add("popularity",5);      
  tell_object(ob,HIY"�����F�����A�򯪤j�}�k�����A���I�n��H���ż��C"NOR);
    switch( random(50) )

  {
    case  0..25: new(__DIR__"obj/book")->move(ob);
          break;
    case  26..50: new(__DIR__"obj/fakebook")->move(this_object());

          break;
    }
  
   ::die();
  return;
}



