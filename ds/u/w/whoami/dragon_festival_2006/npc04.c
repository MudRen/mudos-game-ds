#include <ansi2.h>
inherit NPC;
inherit SSERVER;

void init();
void combat_ai();
void eat_corpse();
void npc_check();

void create()
{
 switch( random(5) )
 {
 case 0: set_name(HIC"�谭"NOR, ({"nishiki"}) ); break;
 case 1: set_name(HIY"�װ�"NOR, ({"kirameki"}) ); break;
 case 2: set_name(HIB"�ᰭ"NOR, ({"touki"}) ); break;
 case 3: set_name(HIR"����"NOR, ({"shuki"}) ); break;
 case 4: set_name(CYN"�ٰ�"NOR, ({"zanki"}) ); break;
 case 5: set_name(HIW"�Z��"NOR, ({"banki"}) ); break;
 }
  set("limbs", ({ "�Y��", "����","����","�I��","�ⳡ" }) );
  set("verbs", ({ "bite", "claw"}) );
  set("race", "beast");
  set("unit","��");
  set("age",random(50)+50);
  set("gender", "����" );
  set("level",45+random(3));
  set("title",RED"�ݤȰ���"NOR);
  set("evil",-50);
  set("dodge",100+random(100)); 
  set("unarmed",100+random(100));
  set("parry",100+random(100)); 
  set("max_hp",8000+random(3000));
  set("addition/hit",random(30)); 
  set("addition/dodge",random(30)); 
  
  set("addition/bar",random(5)); 
  set("addition/wit",random(5));

  set("addition/str",random(30)); 
  set("addition/dex",random(30)); 
 
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
       (:combat_ai():),                     
     }));
  set_temp("_DRAGON_FESTIVAL_NPC_",1);
  setup();
  set_living_name("_DRAGON_FESTIVAL_GHOST_");  
}

void eat_corpse()
{
     object ob=this_object(), me=this_player(), *inv;
     int x, y;
     inv = all_inventory(environment(ob));
     y = sizeof(inv);
     for(x=0;x<y;x++){
        if( inv[x]->is_corpse() ){
            if( !inv[x] || !ob ) break;
            message_vision("$N�j�f�j�f����$n�Y�F�U�h..\n", ob, inv[x]);
            destruct(inv[x]);
            this_object()->receive_heal("hp", random(500));         
        }      
     }
     return;
}     

void die()
{
  object ob, ob1=this_object();
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    destruct(ob1);
    return;
  }
          switch(random(6)){
          case 0: new(__DIR__"obj/item21")->move(environment(ob)); break;
          case 1: new(__DIR__"obj/item22")->move(environment(ob)); break;
          case 2: new(__DIR__"obj/item23")->move(environment(ob)); break;
          case 3: new(__DIR__"obj/item24")->move(environment(ob)); break;
          case 4: new(__DIR__"obj/item25")->move(environment(ob)); break;
          case 5: new(__DIR__"obj/item26")->move(environment(ob)); break;
          case 6: new(__DIR__"obj/ticket")->move(environment(ob)); break;
          }
//        ob->add("popularity",1);
//        tell_object(ob,HIG"�]���A�����F�ݤȯS�O���ǡA�A�o��F���I�n��\n"NOR);
  message_vision("$N��פ��F$n�j�P����աA��z���F�C\n",this_object(),ob);   
  destruct(this_object());
  return;
}

void init()
{
     ::init();
     npc_check();
     return;
}

void combat_ai()
{
     int w, x, y, z;
     object ob=this_object(), me=this_player();
     x = me->query_bar();
     y = ob->query_bar();
     z = x - y;
     if( z < 0 ) z = 1;
     if( ob->query("hp") < ob->query("max_hp")/3 )
         random_move();

     message_vision("�q�q�q~~\n",ob,me);
         for(w=0;w<z;w++){
         ob->add_temp("apply/bar",z);
         COMBAT_D->do_attack(me,ob,me->query_temp("weapon"),4);
         COMBAT_D->report_statue(ob);
         ob->add_temp("apply/bar",z);
         }
     return;    
}

// �l���ˮ`
varargs int receive_damage(string type, int damage, object who)
{
        int val;

                if(this_object()->is_fighting() ) {

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(100)<30)
                {
                                damage/=4;
                                message_vision(HIY"$N��������������\n" NOR,this_object());
                }
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);
                return damage;
}

void npc_check()
{
     object ob=this_object(), me=this_player(), *inv;
     int x, y;
     inv = all_inventory(environment(ob));
     y = sizeof(inv);
      
     for(x=0;x<y;x++){
     if( !inv[x] || !ob ) break;                     
     if( !userp(inv[x]) && inv[x]->is_character() ){
        if( !inv[x]->query("no_fight") && !inv[x]->query_temp("_DRAGON_FESTIVAL_NPC_") )
        {
         message_vision("$N��$n�����F!!\n", ob, inv[x]);
         inv[x]->die();
         eat_corpse();
        }
     }
     }   
}
