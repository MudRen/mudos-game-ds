#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();
void create()
{
  set_name(WHT"�Ԥ�"NOR, ({"qin xin","xin"}) );
  set("long",@LONG
�b�j���Q�~�e�A����X�F�@�쵽���X�����֫L�A�N�s���k���a
�K�����W�W�U�U������o��֫L�A��������t�G�A�o��֫L��M
�����b����W�A����ۤF�]�D�A�@�w����]�C
LONG
);
  set("gender", "�k��");  
  set("race", "�H��");
  set("age",31);
  set("level",48);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",HIC"�ʦ~"NOR+CYN"����"NOR); 
  set("Merits/bar",13);
  set("Merits/bio",10);
  set("Merits/wit",1);
  set("Merits/tec",10);
  add("addition_damage",200);
  add("addition_armor",100);
  set("max_hp",10500);
  set("chat_chance", 30); 
  set("chat_chance_combat",80);
  set("chat_msg_combat",({
  (: command("do wield claw") :),
  (: command("do wield claw") :),
  (: command("do wield claw") :),
 (: command("do wield claw") :),
 (: command("do wield claw") :),
 (: command("do wield claw") :),
 (: command("do wield claw") :),
 (: command("do wield claw") :),

}));

  setup();
  carry_object(__DIR__"eq/eq2")->wear();
  carry_object(__DIR__"wp/wp2")->wield();
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
    message_vision(HIY"\n$N"HIY"����}�B�A����ީ�y���A�W�իݵo�ǳƨϥX�讱���ǡy�ʪ�H�S�z�I�I\n"NOR,me);
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
      damage = 250+random(200);
      message_vision(HIR"\n$N�Q��P���讱�����n�`�A����˦a�h�������I�I........ "HIR"("+damage+")\n\n"NOR,inv[i]);
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
  "NOR+CYN"\n\n\t�C����Ǩ��n�s��....�a��C����ĤG�h "WHT"�Ԥ� "HIW"�Ѧb"HIY+ob->query("name")+HIW"��W\n\n"+NOR
       ,users());
  ob->add("popularity",5);      
  tell_object(ob,HIY"�����F�����A�򯪤j�}�k�����A�T�I�n��H���ż��C"NOR);
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


