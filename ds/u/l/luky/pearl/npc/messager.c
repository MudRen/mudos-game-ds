#include <ansi.h>
#include <path.h>
inherit NPC;
inherit F_CLEAN_UP;
void create()
{
set_name("[1;34m���Ѿ����H[m",({"messager"}));
set("title","[1;33m�ܢޢ�[m");
set("level",40);
set("age",500);
set("evil",random(500));
set("long","�o�O�@�ӥi�H���A�Ǹ�(message)�������H�A���@���u��d�ܵ��@�ӤH�C\n\n");
set("chat_chance",10);
set("chat_msg",({
(:command,"say":) ,
}) );
        setup();
        set_heart_beat(1);
}
void init()
{
add_action("do_save_message","message");	
}

int do_save_message(string arg)
{
object ob1;
string towho,words;
if(sscanf(arg,"%s %s",towho,words)==2)
 {
  if(ob1=find_player(towho)) return notify_fail("�L�b�u�W��! �ڬݧA�٬O����tell �L������۷N.\n");
  set_temp("switch",1);
  set_temp("sender",this_player()->query("name"));
  set_temp("reciver",towho);
  set_temp("words",words);
  write("���ѹ�A��: �A�n��"+towho+"���d���w�g�����F, �L�@�W�u�ڴN�|�i�D�L.\n");
  return 1;
 } else
    return notify_fail("�榡: message [who] [�T��] \n");
}
void heart_beat()
{
 object me,who,sendob;
 string *message;
 int i;
 me = this_object();
if(query_temp("switch"))
{
 if(who=find_player(query_temp("reciver")))
 {
  tell_object(who,"[1;37m�i���ѡj���z���d��("+query_temp("sender")+"):"+query_temp("words")+"[m\n");
  set_temp("switch",0);
 }
}
::heart_beat();
if( me->query("hp") < 0 ) me->die();
}

void die()
{
object ob,ob1,a,ob2;
int expp;
if( !ob = query_temp("last_damage_from") )
ob = this_player();
seteuid(geteuid(ob));
//ob->set_temp("oten",1);
a=environment(ob);
a->delete("objects");
if( !ob ) return;
message_vision("\n[1;37m���Ѫ����γv���Ƭ��@��C���Ϊ�..[m\n",ob);
//shout(HIC"\n\n�h��F���ӥ@���� �C�� �کZ �ש�Q"+ob->query("name")+"�ʦL���]�C�����F!!\n\n"NOR);
ob1=new(LUKY+"wp/otensword.c");
ob1->move(a);
expp=60000-(ob->query("level")*(1000+random(300)));
if(expp<1) expp=random(17000);
ob->add("exp",expp);
tell_object(ob,"\n�A�o��F"+expp+"�I�g���.\n");
//   ::die();
//ob2 = present("corpse", environment(ob));
//if(!ob2) message_vision("�䤣��corpse..\n",ob);
//else message_vision("���corpse�F!!\n",ob);
//destruct(ob2);
destruct(this_object());

}
