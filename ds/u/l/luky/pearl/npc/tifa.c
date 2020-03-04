// tifa.c

#include <path.h>
#include <ansi.h>
#include <dbase.h>
#define STOREDROOM LUKY+"pearl/temp/potion"
inherit NPC;


void create()
{
set_name("[1;33m���k[0m",({"tifa","boss","npc"}));
set("gander","�k��");
set("long","    �o�O�ѹp�����ħ������R�k����M���M�O�k�ʡM���O�q�p�K�V\n"
+"�O�צ�氫�ޥ��C�����P��O�ݳƪ��o�Mť���٦��t�@�Ө���.. \n"
);
set("level",54);
set("age",23);
set("title","���A�氫�a");
set("coin",random(3500));
set("class","worker");
set_skill("rapid",80);
set_skill("strike",276);
//map_skill("unarmed","tenken");
set_temp("apply/armor",540);
set_heart_beat(1);
setup();
carry_object(__DIR__"eq/blue_clo")->wear();
carry_object(__DIR__"wp/tigerglove")->wield();
}

void heart_beat()
{
 object me,opp,*goods,ob,ob2,stroom;
 string oppid;
 me = this_player();
 opp=query_temp("last_damage_from");
 if(opp)
 {
  oppid=opp->query("id");
  if( this_object()->is_fighting() )
  {
   if(random(8)>6) 
   {
    command("strike");
   } else
   if(random(9)>7) 
   {
    command("rapid");
   }
  }
 }
 if ( (query("hp")<30000) && (random(5)>1))
 {
//  load_object(STOREDROOM);
//  stroom=find_object(STOREDROOM);
  load_object(STOREDROOM);
  stroom=find_object(STOREDROOM);
  goods = all_inventory(stroom);
  if(ob=present("caca potion",stroom))
  {
   if(ob->query("amount"))
   {
    message_vision(HIW"���k�q�d�i���X�@�~�d�d�Ĥ�.."NOR,this_player());
    ob2=new(base_name(ob));
    ob2->delete("secured");
    ob2->move(this_object());
    ob->add("amount",-1);
    command("drink potion");
   } else ob->move(this_object());
  } else command("say �V�|!!�S�ĤF!!");
 } 
 ::heart_beat();
 if(me)
 {
  if (me->query("hp") < 0)
  me->die();
 }
}

void die()
{
object ob;
object a;
if( !ob = query_temp("last_damage_from") )
ob = this_player();
ob->set_temp("ovelia",1);
a=environment(ob);
a->delete("objects");
if( !ob ) return;
message_vision(HIR"\n\n  �ڡ�㸦�k�G�s�@�n!!  \n\n"NOR,this_player());
   ::die();
destruct(this_object());
}