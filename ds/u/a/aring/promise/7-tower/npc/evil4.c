#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();
void create()
{
  set_name(WHT"�ݦ�"NOR, ({"can si","can"}) );
  set("long",@LONG
�e�w�b�Z�L�M�Q����l�A���N�b�G�Q�~�e�M�Q�a�G�D��������_�A
�ݦ��N�J�F�]�D�A�ӫ�Ӥ]�ߴN�F�U���U�����M�k�Z�ǡA�۳ФF�@
�ۦW���ݯ}�M�v�����ǡC
LONG
);
  set("gender", "�k��");  
  set("race", "�H��");
  set("age",28);
  set("level",50);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",HIW"������"NOR); 
  set("Merits/bar",10);
  set("Merits/bio",10);
  set("Merits/wit",3);
  set("Merits/tec",15);
  add("addition_damage",310);
  add("addition_armor",300);
  set("max_hp",11000);
  set_skill("stone-blade",100);
  map_skill("blade","stone-blade");

  set("chat_chance", 30);
  setup();
  //carry_object(__DIR__"eq/eq4")->wear();
  carry_object("/open/world1/wilfred/sand/npc/wp/wp4")->wield();
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
    message_vision(HIC"\n$N"HIC"�H�D�`���ֳt�����઺�⤤���M�I�I
\n"NOR,me);
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
      message_vision(HIC"�M�ӪŮ𤤪������l�y�ɾ����A�򱵵�$N"HIC"�j�n�۵ۡG�ݯ}�M�v...........\n\n"NOR,me);   
      damage = 300+random(100);
      message_vision(HIB"�D����ƴX�Q�D���ݼv�����A"HIW"$N"HIB"�����.......�C"HIR"("+damage+")\n\n"NOR,inv[i]);
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
  "NOR+CYN"\n\n\t�C����s��....�a��C����ĥ|�h "WHT"�ݦ� "HIW"�Ѧb"HIY+ob->query("name")+HIW"��W\n\n"+NOR
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



