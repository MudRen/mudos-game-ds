// �쬰 MD �� mob, �]�w�PDS ���P, �ФŰѦ�
#include <ansi.h>
inherit NPC;
inherit SSERVER;
void create()
{
set_name("[1;30m�کZ[0m",({"swordsoul oten","oten"}));
set("title","[1;34m�C��[m");
set("level",60);
set("age",500);
set("war",1);
set("evil",200+random(200));
set("long","�A�ݨ�@��¦⪺�Z���M�b�@���@���W�A���@�S���ͩR����H�C\n\n");
set("chat_chance",10);
//set("attitude", "aggressive");
set("chat_msg",({
(:command,"say":) ,
"�C�� �کZ�o�X�@�}�}�C�I���D�u.....��..�ڰڰ�........\n",
}) );
add_temp("apply/armor",70);
add_temp("apply/damage",70);
 setup();
}

int filter_listener(object ppl)
{
        if( !environment(ppl) ) return 0;
        if( ppl->money_type() != this_object()->money_type() ) return 0;
        return 1;
}

void heart_beat()
{
 object target,me,ob,ot;
 int damage,damage2;
 int i;
 me = this_object();
 ::heart_beat();
 if(!me) return;
 if( me->is_fighting() )
 {
  target = offensive_target(me);
  if(!target) return;
  if(environment(me)!= environment(target) ) return;
  if(random( target->query_dex() ) < 10  )
  {
   damage=200+random(400);
   damage2 = target->query("hp")/5;
   if(damage2 < 100) damage2 = 50+random(100);
   if(target->query_temp("slash")<1)
   {
   message_vision(HIR"\n\n �@ ��..���ڡ�����ڡ�㫢�㫢��㫢��㫢����\n",me);
   message_vision(@DIE
                       ______
                    .-"      "-.
                   /            \
       _          |              |          _
      ( \         |,  .-.  .-.  ,|         / )
       > "=._     | )(__/  \__)( |     _.=" <
      (_/"=._"=._ \/     /\     \/ _.="_.="\_)
             "=._"(_     ^^     _)"_.="
                 "=\__|IIIIII|__/="
                _.="| \IIIIII/ |"=._
      _     _.="_.="\          /"=._"=._     _
     ( \_.="_.="     `--------`     "=._"=._/ )
      > _.="                            "=._ <
     (_/                                    \_)
DIE
,me);
   message_vision("\n[1;30m�C�� �کZ���|���C�V$N[1;30m����V�����ĥh!![m\n",target);
   message_vision(HIW"�������·t�����L�@�D���~�� $N"HIW"���y��@���G��!! "HIR"("+damage2+")\n"NOR,target);
   target->receive_damage("hp",damage2,me);
   target->set_temp("slash",3);
   } else
    {
     message_vision(HIB"\n\n�C��g���D: ��..���ڡ���"HIR"���ڡ�㫢�㫢��㫢��㫢����\n",me);
     message_vision(HIR"$N"HIR"���W���C�����_���y�X�@�i�i�A��..("+damage+")\n"NOR,target);
     target->receive_damage("hp",damage,me);
     target->add_temp("slash",-1);
    }
   } 
 }
}

void die()
{
 object ob,ob1,a,ob2,owner,*user;
 int expp;
 ob = query_temp("last_damage_from");
 if(!ob) ob = this_player(1);
 owner=ob->query("creater");
 if(owner) ob=owner;
 if(ob)
 {
 	user = filter_array( users(), "filter_listener", this_object() );
	message("system",HIC"\n\n�h��F���ӥ@���� �C�� �کZ �ש�Q"+ob->query("name")+HIC"�ʦL���]�C�����F!!\n\n"NOR,user);
 }

  if(!a = environment(this_object())) { destruct(this_object()); return; }
  message_vision("\n[1;37m�C�� �کZ�����γv���Ƭ��@��C���Ϊ�..[m\n",this_object());
  
  ob1=new(__DIR__"wp/otensword.c");
  ob1->move(a);
  expp=50000-(ob->query("level")*(500+random(500)));
  if(expp<1) expp=random(17000);
  ob->add("exp",expp);
  tell_object(ob,"\n�A�o��F"+expp+"�I�g���.\n");
  ob->set_temp("killoten",1);
  ob->save();
  destruct(this_object());
 
}
