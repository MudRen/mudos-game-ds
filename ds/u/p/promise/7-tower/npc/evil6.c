#include <ansi.h>
#include <combat.h>
inherit NPC;
 
void fly();
void create()
{
  set_name(WHT"�`��"NOR, ({"yao ni","ni"}) );
  set("long",@LONG
��������k��ű�j�W�K�A�@�ͷ�ű�X�Ƨ⵴�@���L�A���]�g��
�W�Q�ɭP�̫�D�H���`�P�l���A�ӼY�J�F�]�D�����C
LONG
);
  set("gender", "�k��");  
  set("race", "�H��");
  set("age",27);
  set("level",55);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",HIM"�d����"NOR); 
  set("Merits/bar",15);
  set("Merits/bio",15);
  set("Merits/wit",15);
  set("Merits/tec",15);
  set_skill("sorgi_sword", 100);
  set_skill("star-sword", 100);
  set_skill("sevenstar-sword", 100);
  set_skill("sevenstar", 100);
  set_skill("force", 100);
  set_skill("moon_force", 100);
  set_skill("fogseven", 100);
  map_skill("dodge","fogseven");
  add("addition_damage",300);
  add("addition_armor",200);
  set("chat_chance", 30);
  set("max_hp",15000);
        set("chat_msg", ({
                (: fly :),
                 (: command("exert moon_force recover") :),
        }));
 set("chat_chance_combat", 60);
         set("chat_msg_combat", ({
                (: command("do wield umbrella,exert sevenstar") :),
                (: command("do wield umbrella,exert sevenstar") :),
                (: command("do wield umbrella,exert sevenstar") :),
                (: command("do wield umbrella,exert sevenstar") :),  
                    (: command("do wield unbrella,exert sevenstar") :),  
                   (: command("exert moon_force long-arc") :),
   }));
  setup();
  //carry_object(__DIR__"eq/eq6")->wear();
  carry_object(__DIR__"wp/wp6")->wield();
  carry_object(__DIR__"wp/wp6");
  carry_object(__DIR__"wp/wp6");
  carry_object(__DIR__"wp/wp6");
  carry_object(__DIR__"wp/wp6");
  carry_object(__DIR__"wp/wp6");
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
    message_vision("\n$N"HIW"���R������"HIG"�K����"HIW"�A�t�x���I�i"HIG"�K����"HIW"����"HIY"�i������j"HIW"�I�I\n"NOR,me);
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
      damage = 100+random(200);
      message_vision(HIW"      
$N"NOR"���ߦ�@�_�A�y�ɳ·��F���֡A�믫�W����"HIW"���֪��ж�"NOR"�I�I"HIR"("+damage+")\n\n"NOR,inv[i]);
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

varargs int receive_damage(string type, int damage, object who)
{
        object me = this_object();
        object sword;
        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
        if( !random(3) ) 
        {
                foreach(object one in filter_array( children("/daemon/skill/npc/sword"), (: clonep :) ) )
                {
                        if( one->query_leader() == me ) sword = one;
                }
                if( sword ) {
                message_vision(HIM"$n��M�b$N�e�ɤU���������I\n", me, sword);
                sword->receive_damage(type,damage,who);
                damage = 0;
                }
        }
        else {
                ::receive_damage(type,damage,who);
                if( !random(5) )
                {
                        me->set("flee", 1);
                        me->help();
                }
        }

        return damage;
}

void fly()
{
        int num = SKILL_D("sevenstar")->check(this_object(), 0);
        if( num >= 5 ) return;

        command("do wield umbrella,exert sevenstar,exert sevenstar");
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
  "NOR+CYN"\n\n\t�C����Ǩ��n�s��....�a��C����Ĥ��h "WHT"�`�� "HIW"�Ѧb"HIY+ob->query("name")+HIW"��W\n\n"+NOR
       ,users());
  ob->add("popularity",5);      
  tell_object(ob,HIY"�����F�����A�򯪤j�}�k�����A�C�I�n��H���ż��C"NOR);
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


