#include <ansi.h>
#include <combat.h>
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$N���ۭ�r��"HIY"����"NOR"����������$n�����h�I",
                "attact_type":  "bar",
                "damage_type":  "���",
        ]),
        ([  "action":       "$n���e�@�¡A�Q���"HIW+BLK"�K��"NOR"��$N�������F�@�U�A����w�t�I",
                "attact_type":  "tec",
                "damage_type":  "����",
        ]),
        
});
void do_clean(); 
void summon();
void create()
{
  set_name(WHT"�l��"NOR, ({"zi er","er"}) );
  set("long",@LONG
�W�r�ݦ��X�z�A��ꤣ�M�A���H�髬��r�L��A�⤤����䭫�L��
�A���諸�@�����Ҥ]�Q���­��C
LONG
);
  set("gender", "�k��");  
  set("race", "�H��");
  set("age",42);
  set("level",51);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",HIG"ͼ���L"NOR); 
  set("Merits/bar",10);
  set("Merits/bio",10);
  set("Merits/wit",3);
  set("Merits/tec",3);
  add("addition_damage",210);
  add("addition_armor",100);
  set("max_hp",11100);  
  set("chat_chance_combat",3);
  set("chat_msg_combat",({ 
      (: summon :), 
})); 

  setup(); 
  set("actions", (: call_other, __FILE__, "query_action" :));
  //carry_object(__DIR__"eq/eq5")->wear();
  //carry_object(__DIR__"wp/wp5")->wield();
 }
 mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if( this_player()->query_temp("invis")>2 ) return;
  if(userp(this_player()) ) this_object()->kill_ob(this_player());
}
  
void summon()
{
     object me=this_player(),a,b;
     if(this_object()->is_busy()) return;
     else{ message_vision(HIW"\n�l�������m�ݫe�A�R�R����۩G��A���趡���a�X�{ "HIG"2 "HIW"��"NOR"�l��"HIW"�������ӧU�}�I�I\n\n"NOR,me);
           a=new(__DIR__"shadow");
           b=new(__DIR__"shadow2");

          a->move(environment(me));
           b->move(environment(me));
           a->kill_object(me);
           b->kill_object(me);
         }
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
  "NOR+CYN"\n\n\t�C����Ǩӫs��....�a��C����Ĥ��h "WHT"�l�� "HIW"�Ѧb"HIY+ob->query("name")+HIW"��W\n\n"+NOR
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



