// ovelia.c
#include <ansi.h>
inherit NPC;
object gf;
int do_move(string dir);
void create()
{
set_name("[1;37m�Կp��[m",({"lamuza","boss"}));
set("long",
"\n  �Կp���쬰��k�������ꪺ�Q�ڡC�ѩ��k�����M���F�Q�Ȥ��������\n"
"�ɪ��A�޵o�F�ۦW�����~�Ԫ��C��ɩԿp���K�i�J�F�_���M�h�Τh�x�ǰ|\n"
"���V�A���ѩ�P�������������Ժ��ڥj�����`�A�ϱo�L�Q���Ŧ����ħL�A\n"
"�]�]���Ӧb�@�����@�Ԥ��۫��F�����R�����D�C\n"
);
set("title","�h��i��");
set("level",65);
set("age",38);
set("evil",-100);
set("gander","�k��");
set("class","wufo");
set_skill("force",1100);
set_skill("rapid",180);
set_skill("stab",160);
set("setforce","basic");
add_temp("apply/armor",random(300));
add_temp("apply/damage",random(100));
set("coin",random(2400)+1000);
set("chat_chance", 15 );
set("chat_msg", ({
(:command("say �@�Ӧn���_�I�����ӭn�`�`�j�M(search)�@�ǥi�ê��ƪ�."):),
(:command("say ���ɭԤ����ݰ�(ask)NPC�@�ǰ��D(�pname)..�γ\\�|���N�Q���쪺��ì."):),
(:command("idle"):),
(:command,"get potion":),
(:command("smile"):),
}) );
set("chat_chance_combat",5);
set("chat_msg_combat",({
(:command,"angry":),
(:command,"rapid":),
(:command,"drink potion":),
}));
set("inquiry/name", @LONG
  �ڪ��W�r�s�Կp��, �O�o�̪�����.
LONG );
set("inquiry/ovelia", @LONG
  �����R��? ���ڬ��ڤ��˳�������ڷ|�V�o�D�B��. 
LONG );
set("inquiry/service", @LONG
  �ӤW�N�O�ȩ�, �ФW�ӥ𮧧a.
LONG );

set_temp("exforce",1);
set_heart_beat(1);
setup();
carry_object(__DIR__"eq/greenarmor")->wear();
carry_object(__DIR__"eq/greenarms")->wear();
carry_object(__DIR__"eq/greenleg")->wear();
carry_object(__DIR__"eq/greenbelt")->wear();
carry_object(__DIR__"eq/greenboots")->wear();
carry_object(__DIR__"eq/greenhelm")->wear();
carry_object(__DIR__"eq/greenshield")->wear();
carry_object(__DIR__"wp/greensword")->wield();
}
void init()
{
 gf=find_living("ovelia");
 set_heart_beat(1);
 if( this_player()->query_temp("ovelia")==1)
 {
  write("�Կp���j�s: �i�c���å�~~ �~�M���F�ڳ��w���H~~�ǩR��!!!\n");
  kill_ob(this_player());
 }
}

void heart_beat()
{
 object me,opp,temp,opp1,opp2;
 string oppid, owner;
 int gfhp,dam;
 me = this_player();
 if(!environment(this_object())) return;
// gf=present("ovelia",environment(this_object()));
 if(!gf) gf=find_living("ovelia");
// if(!gf) tell_room(environment(this_object()),"�S���.. (1)\n");
 if(gf && gf->is_fighting() )
 {
  opp1=gf->query_temp("last_damage_from");
  gfhp=gf->query("hp");
  if(!this_object()->is_fighting())
  if(gfhp<20000 && !present("ovelia",environment(this_object())) && gf->is_fighting() )
  {
   tell_room(environment(this_object()),"\n�Կp�����h�϶����R���F..\n",);
   this_object()->move(environment(gf));
   tell_room(environment(this_object()),"\n�Կp���ܥͮ𪺽ĤF�i��!!\n\n",);
   if(opp1)
   if(opp1->query("hp")>300)
   {
    kill_ob(opp1);
    opp1->set_temp("lamuza_k",1);
    if(owner=opp1->query_temp("owner"))
    {
     opp2=find_player(owner);
     if(opp2)
     {
      kill_ob(opp2);
      opp2->set_temp("lamuza_k",1);
     }
    } 
   }
   set("chat_chance", 30);
   set("chat_msg", ({
   (:random_move:),
   }) );
  }
  if(gf->is_fighting()) opp1=gf->query_temp("last_damage_from");
  if(opp1)
  if(!this_object()->is_fighting(opp1) && gf->is_fighting(opp1) && present("ovelia",environment(this_object())) )
  {
   if(opp1->query("hp")>1)
   { 
    kill_ob(opp1);
   }
  }
 }
opp=opp2;
if(!opp) opp=opp1;
if(!opp) opp=query_temp("last_damage_from");
if(opp)
{ 
 if( this_object()->is_fighting() && present(opp->query("id"),environment(this_object())) )
 {
  if ( !query_temp("body") && (random(5)>2))
  {
   message_vision(HIW"�Կp��"NOR"�B�ίu���@��,���[�P��ֽ�����u�𪺫O�@.\n",this_object());
   this_object()->add_temp("apply/armor",150+random(400));
   this_object()->set_temp("body",1);
  } else
  if ( !query_temp("enforce") && (random(5)>3))
  {
   command("spank");
   message_vision(HIW"�Կp��"HIG"�j�ܤ@�n, ���H�N��, �԰���O�����W�[�F����.\n"NOR,this_object());
   this_object()->add_temp("apply/damage",200+random(200));
   this_object()->set_temp("enforce",1);
  } else
  if ( (random(7)>5) && opp->query("hp")> 1000 )
  {
   if(present( opp->query("id"), environment(this_object()) ) )
   {
    command("hmm");
    command("say �K�K...�A���}��N�O�o��!!");
    dam=1100-opp->query_temp("apply/armor")/2;
    dam+=random(600);
    if(dam<500) dam=300+random(300);
    message_vision(HIW"�Կp��"HIG"���_�񴹼C�ΤO��$N"HIG"���n�`��U�h."HIM"("HIR+dam+HIM")\n"NOR,opp);
    opp->receive_damage("hp",dam,this_object());
   }
  }
 }
}
 ::heart_beat();
 if(!me) return;
 if (me->query("hp") < 0)  me->die();
}

void die()
{
object ob;
object a;
if( !ob = query_temp("last_damage_from") )
ob = this_player(1);
if( !ob ) return;
ob->delete_temp("ovelia");
ob->delete_temp("lamuza_k");
a=environment(ob);
a->delete("objects");
shout(HIG"\n\n ������...�n��"+ob->query("name")+"!!! "
+HIG"�~�M������ѧکԿp��...\n\n"
"                 �Y��N�o�O�q�Φb���~, �A���e�~�N���i���q!!\n\n"NOR);
   ::die();
destruct(this_object());
}