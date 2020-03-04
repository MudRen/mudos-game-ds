#include <ansi.h> 
inherit NPC;
 
void create() 
{ 
  set_name(CYN"�ȪZ"HIW"���t"NOR,({"shang-woo god turtle","turtle"}));
  set("long",@LONG      
�g�˪��F��A�s�Y�t���A�����q��ήe�A�쥻�V�v����
�����]�U�F�߷R�������A���X�F�����C
LONG
  ); 
  set("race", "beast");
  set("level",45+random(15));
  set("max_hp",35000); 
  set("age",432+random(32));      
  set("attitude","unfriendly");
  set("devil",20); 
  set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����","�t��" }) );
  set("verbs", ({ "bite","claw"}) ); 
  set("chat_msg", ({
     (: this_object(), "random_move" :), 
      "�ȪZ���t�n�F�n���ڡA�ê`���۬Y�˪F��C\n" }) );
  setup();
  set_living_name("pool_npc");
  carry_object(__DIR__"obj/turtle-armor")->wear();
}
   
int special_attack(object me,object target,int hitchance)
{
  int tdex,tcon; 
  if(!me || !target) return 0;
  if(random(10)) return 0;
  tdex=target->query_dex();
  tcon=target->query_con();
  if( random(hitchance*30) > tdex+tcon )
  {
    message_vision("\n\n$N�j����V�ۤv���{�l�A�L���H�Y�R�X�@��"+HIR"���y�I\n"
                    +HIW"�e�t���ƦV$n..\n"
                    +HIR"�y���I�������ˡI\n\n"+NOR,me,target);  
    target->receive_damage("hp",500+random(333), this_object());
    return 1; 
  }
}
 
void die()
{
  object ob,obj;
//  obj=new(__DIR__"obj/turtle-armor");
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  message("world:world1:vision",
  HIY"\n\t�i���H�P�}�j\n"
  CYN"\t\t\t�ȪZ���t "+HIR "�Q"+ob->name(1)+"�����ŤF�I\n\n"+NOR,users());
  ob->add("popularity",4); //�n��
  message_vision( "$N�@�Y���b�a�W�A�Y�W���ȥۤ]�H������" ,this_object() );
//  obj->move(environment(this_object() ) );
  obj=new(__DIR__"obj/turtle-liver");
  obj->move(environment(this_object() ) );
  ::die();
  return;
}

