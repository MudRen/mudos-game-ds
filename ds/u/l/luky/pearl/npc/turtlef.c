// TURTLEF.c
#include <path.h>
#include <ansi.h>
inherit NPC;

    void create()
{set_name(HIY"���t����"NOR,({"elder turtle","turtle"}) );
set("gender", "�k��");
set("level",50);
//set("ridable",1);
set("age",100);
set("evil",-300);
set("long", "�@���­����j���t�A�I�W�٦��@�Ǥp�աC\n");
//set_temp("apply/armor",240);
set_temp("apply/damage",180);
set("limbs", ({ "�Y��", "����", "�e�}", "��}","����"}));
set("verbs", ({ "bite"}));
set("chat_chance",10);
set("chat_msg",({
(:command,"say �A�̧�ڬO�Q�ݧڤ���ƶ�? ":),
"�Ѯ��t�ܥͮ𪺬ݵۧA.\n",
}) );
 setup();
 load_object(__DIR__"halfshark");
 set_heart_beat(1);
}

void init()
{
add_action("do_ask","ask");
}

int do_ask(string arg)
{
 object obj,me;
 mixed msg;
 string who;
 me=this_player();
 msg=({
  " ��.. ���ڷQ�Q..",
  " �ɩԬO�W�ӥ@���̰��j���ؿv�v.. �����׹D�|�N�O�L�سy��..",
  " ��F!!�W�����ӳå밽���F�@�i������׹D�|���K���r������.�i���ڬݤ���..",
 });
 if(arg=="turtle about sala" || arg=="elder about sala" )
 {
 message_vision("$N�V"HIY"���t����"NOR"��ť�����ysala�z�������C\n",me);
 call_out("do_say",2,msg[0]);
 call_out("do_say",5,msg[1]);
 call_out("do_say",8,msg[2]);
 if(!query("no_give"))
 {
  call_out("do_give",11,me);
 } else 
 {
  who=query("no_give");
  call_out("do_shake",11,who,me);
 }
 return 1;
 }
 return 0;
}
int do_shake(string who,object me)
{
 tell_object(environment(this_object()),HIY"���t���ѻ��D: "
 +"�ڤw�g�⨺�i�u����"+who+"�F.. �A�ߤF�@�B��..\n"NOR);
 message_vision("���t���ѩ��$N���ӻH..\n",me);
 return 1;
}

int do_say(string str)
{
tell_object(environment(this_object()),HIY"���t���ѻ��D: "+str+"\n"NOR);
return 1;
}

int do_give(object me)
{
 object obj;
 tell_object(environment(this_object()),HIY"���t���ѻ��D: "
 +"�N�O�o��.. �A���h�n�F, �ϥ��گd�ۤ]�S�����.\n"NOR);
 this_object()->command("say "," �N�O�o��.. �A���h�n�F, �ϥ��گd�ۤ]�S�����.");
 obj=new(__DIR__"item/paper");
 if ( (obj->query_weight()+me->query_encumbrance())>me->query_max_encumbrance() )
 {
  command("look "+this_player()->query("id"));
  command("say �i�O�A���W�F��Ӧh�F, �j�����A�]������..�U���a!");
  return 1;
 }
 obj->move(me);
 message_vision("���t���ѵ�$N�@�i��.\n",me);
 this_object()->set("no_give",me->query("id"));
 return 1;
}

void heart_beat()
{
 object *enemy,ene;
 object me;
 int damage;
 int i;
 if(!me=this_object()) return;
 if(me->is_fighting())
 {
  if(me->query("hp")<30000 && me->query_temp("change")<1)
  {
   message_vision(HIR"\n\n�n�å�!!! �ݨӤ����X�u���ƬO����F..\n\n"
   +HIB+" �j �� �t �� �I �W �� �M �� �X �\\ �h �r �� !!! \n "NOR,me);
   me->set_temp("change",1);
   me->add("str",30);
   me->add("dex",30);
   me->set("max_hp",30000);
   me->add_temp("apply/damage",200+random(100));
   me->add_temp("apply/armor",200+random(100));
   me->set_name(HIM"���t"NOR,({"needle turtle","turtle"}));
   me->set("long","�@���I�W�����r�몺���t�C"HIR"(�e���G�D�`�ͮ�)\n"NOR);
  }
  ene = me->query_temp("last_damage_from");
  if(!ene) return;
  if(!present(ene->query("id"),environment(me)) ) return ;
  
  if(me->query_temp("change")==1)
  {
   if( me->is_fighting() )
   if(random(300)>200)
   {
    damage=1400+random(1000)-ene->query_temp("apply/armor");
    if(damage<500) damage=500+random(300);
    if(random(100)>62)
    {
     message_vision("$N"HIC"��M���A����V�ĹL��,�������V$n�@��,�y��"HIR+damage+HIC"�ˮ`!\n"
     NOR,me,ene);
     ene->receive_damage("hp",damage,me);
     COMBAT_D->report_status(ene,1);
    }
   }
  }
//if(me->query("hp")<0)
//command("begin war");
  ::heart_beat();
 }
 if(me)
 {
  if(me->query("hp")<0)
  me->die();
 }
}

void die()
{
object ob;
if( !ob = query_temp("last_damage_from") )
 ob = this_player(1);
ob->set_temp("kill_turtle",1);
if( !ob ) return;
shout(HIC"\n\n\n          �j�����ǨӤ@�}�s�z����\n\n"
+HIR"              �ڡ�ڡ����\n\n"
HIB"        ���R�������Ȱ_�F�}�}���g�ܥ��� \n\n"NOR);
shout(HIW"�j���t�h�W���j�s: �A��� �M����"HIY+ob->query("name")+HIW"��!! �����O���|��L�A��!!!"+
HIR"\n\n      �گ����J�O���ڡ������ڦu�@�o���j���a!!! \n\n"NOR);
environment(this_object())->set("war",1);
    ::die();
}
