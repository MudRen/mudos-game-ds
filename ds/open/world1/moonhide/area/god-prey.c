#include <ansi.h> 
inherit NPC;  
int CALL_PREY(string arg);
void create()
{
  set_name(CYN"����"NOR, ({"god prey","prey"}) );
  set("long","�j�Ӭ����L�P�p�s�k�����V�A�O�@�ۥj�ӡA�����~�H�I�Z�C\n");
  set("race", "beast");
  set("unit","��");
  set("age",80);
  set("level",50+random(this_player()->query("level")/3)); 
  set("max_hp",9000);
  set_skill("dodge",150);
  set_skill("unarmed",100);
  set("Merits/wit",10);
  set("limbs", ({ "�Y��", "����","�ݳ�","���l","����" }) );
  set("verbs", ({ "bite","claw" }) ); 
        set("chat_chance_combat",9);
        set("chat_msg_combat",({
    (: random_move :),
}));  
  setup(); 
  //carry_object(__DIR__"leather")->wear();
}
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*30) > tdex+tcon)
    {
      message_vision(CYN"\n\n$N"+HIW"���M�@���ƤQ�V���I\n"
                    +HIW"�j�ۦ����V�U�Y���A�H���֪��t��..\n"
                    +HIR"�ļ�$n�A�y���I�������ˡI\n\n"+NOR,me,target);  
     target->receive_damage("hp",600+random(333), this_object());
    } else {
//     this_object()->CALL_PREY();
    }
    return 1;  
}
 
int CALL_PREY(string arg)
{
     object me=this_player(),ob=this_object(),CP_PREY;
     if( ob->is_fighting() )
     { 
     message_vision(CYN"����"+HIW"��M�i�Ͱ����A�b����������D�¼v�I\n\n"+NOR,me);
     CP_PREY=new(__DIR__"empty-god-prey"); 
     CP_PREY->move(ob);
     CP_PREY->kill_ob(environment(this_player())); 
     this_player()->kill_ob(this_object()); 
     }
     return 1;
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
  message("world:world1:vision", 
    HIB"\n\t�˪L�̪��s�~��M�s�_��s�E�E�E��ӬO�E�E�E\n\n"
    +HIY"\t�i�j��  ���V�j"+CYN"����"+HIW"�Q"+ob->name(1)+"�����F�C\n\n"+NOR,users());
  ob->add("popularity",3);
  switch( random(100) )
  {
    case  0..1: new(__DIR__"leather")->move(this_object());
          break;
    case  2..40: new(__DIR__"leather2")->move(this_object());
          break;
    case  41..99: new(__DIR__"leather3")->move(this_object());
          break;
  }
/*      
  if( random(25) ) // �ѭ쥻random(8) �Y16���@���|�o��tec&bar eq �令50���@���|
                   // by alickyuen@ds2003-02-18
    new(__DIR__"leather2")->move(this_object()); 
  else if( random(2) )
    new(__DIR__"leather")->move(this_object());
//        eqp->move(this_object());
//  2003.4.10 �ץ� prey ���ɥ������� bug  by  ksj
*/
  ::die();
  return;
}

