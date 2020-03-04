#include <ansi.h>
inherit NPC;
void create()
{
set_name("[1;30m�کZ[m",({"swordsoul oten","oten"}));
set("title","[1;34m�C��[m");
set("level",65);
set("age",500);
set("war",1);
set("evil",200+random(200));
set("long","�A�ݨ�@��¦⪺�Z���M�b�@���@���W�A���@�S���ͩR����H�C\n\n");
set("chat_chance",10);
set("attitude", "aggressive");
set("chat_msg",({
(:command,"say":) ,
"�C�� �کZ�o�X�@�}�}�C�I���D�u.....��..�ڰڰ�........\n",
}) );
add_temp("apply/armor",700);
add_temp("apply/damage",500);
        setup();
        set_heart_beat(1);
}
void heart_beat()
{
 object *enemy,me,ob,ot,eme;
 int damage,damage2;
 int i;
 me = this_object();
 if(me)
 if( me->is_fighting() )
 {
  enemy = me->query_enemy();
  if(!enemy) return;
//  i=random(sizeof(enemy));
  if(sizeof(enemy)==0) return;
//  eme=present(enemy[random(sizeof(enemy))]->query("id"),environment(me));
  eme=query_temp("last_damage_from");
  if(!eme) return;
  if(! present(eme->query("id"), environment(me) ) ) return ;
  if(random(540-eme->query("lck"))>400 || random(18)<2)
  {
   damage=200+random(400);
   damage2=enemy[i]->query("hp")/5;
   if(eme->query_temp("slash")<1)
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
   message_vision("\n[1;30m�C�� �کZ���|���C�V$N����V�����ĥh!![m\n",eme);
   message_vision(HIW"�������·t�����L�@�D���~�� $N���y��@���G��!! "HIR"("+damage2+")\n"NOR,eme);
   eme->receive_damage("hp",damage2,me);
   eme->set_temp("slash",3);
   } else
    {
     message_vision(HIB"\n\n�C��g���D: ��..���ڡ���"HIR"���ڡ�㫢�㫢��㫢��㫢����\n",me);
     message_vision(HIR"$N���W���C�����_���y�X�@�i�i�A��..("+damage+")\n"NOR,eme);
     eme->receive_damage("hp",damage,me);
     eme->add_temp("slash",-1);
    }
   } 
 }
 ::heart_beat();
 if(me)
 {
  if( me->query("hp") < 0 ) me->die();
 }
}

void die()
{
 object ob,ob1,a,ob2;
 int expp;
 string owner;
 ob = query_temp("last_damage_from");
 if(!ob) ob = this_player();
 owner=ob->query_temp("owner");
 if(owner)
 {
  ob=find_player(owner);
  if(!ob) ::die();
 } 
 if(ob)
 {
  a=environment(ob);
  a->delete("objects");
  if( !ob ) return;
  message_vision("\n[1;37m�C�� �کZ�����γv���Ƭ��@��C���Ϊ�..[m\n",ob);
  shout(HIC"\n\n�h��F���ӥ@���� �C�� �کZ �ש�Q"+ob->query("name")+HIC"�ʦL���]�C�����F!!\n\n"NOR);
  ob1=new(__DIR__"wp/otensword.c");
  ob1->move(a);
  expp=400000-(ob->query("level")*(3000+random(500)));
  if(expp<1) expp=random(17000);
  ob->add("exp",expp);
  tell_object(ob,"\n�A�o��F"+expp+"�I�g���.\n");
  ob->set("killoten",1);
  ob->save();
  tell_object(ob,"\n�γ\\�A�ӧ�|���ݬݦ��S�����y..\n");
  //   ::die();
  //ob2 = present("corpse", environment(ob));
  //if(!ob2) message_vision("�䤣��corpse..\n",ob);
  //else message_vision("���corpse�F!!\n",ob);
  //destruct(ob2);
  destruct(this_object());
 }
}
