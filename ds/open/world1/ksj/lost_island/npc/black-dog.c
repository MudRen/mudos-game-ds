#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$N�Ƭ��@�ζ�����L$n�A$n��$l�P��p�k���몺�@�h",
                "attact_type":  "sou",
                "damage_type":  "���F�ˮ`",
        ]),
});

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(HIW""BLK"�v��"NOR, ({"black dog","dog"}) );
  set("long",@LONG
�@�Τ��Ϊ��¼v�A�L�k�P�_���O�ʪ��٬O�]���άO�ջ�A�ڻ����q�`
���é�v�l���A�ܩ�䥦���Ʊ����@�L�Ҫ��C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",70);
  set("gender", "����" );
  set("level",42+random(4));
  set("title","  �����~ ");
  set("limbs", ({ "�¼v" }) );
  set("verbs", ({ "bite","claw" }) );
  set("str",39);
  set("con",91);
  set("int",70);
  set("dex",85);
  set("Merits/sou",5);
  set("combat_exp", 300000);
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
      "�Aı�o���᪺�v�l�n�����I���ʡH\n",
     }));
  set("chat_chance_combat", 30 );
  set("chat_msg_combat", ({
     (: random_move :),
     }) );
  set_temp("apply/dodge",100);
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  carry_object(__DIR__"eq/black-dog-bone")->wield();
}

void init()
{        
  ::init();
  switch( random(20) )
  {
    case 0..18:
         this_object()->set_temp("hide",1);
         break;
  }
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
  {
    this_player()->receive_damage("mp",random(10),this_object());
    if( this_object()->query("hp")+100 < this_object()->query("max_hp") )
      this_object()->receive_heal("hp", random(100));
  }
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
