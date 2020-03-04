#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�������D",({"the city master","master"}) );
        set("long",
"�a�U�����D, �b�L���ɷɮ�R�O�K�����y�W, �����ݥX�@��䪺�~�ˡC\n"
        );
        set("age",74);
        set("level",49);
        set("race","�H��");
        set("attitude", "peaceful");
        set("chat_chance",5);
        set("chat_msg",({
                (:command("reload clip"):),
                "���D���D�G�u��..�o�i����~�n��...�v�C\n",
        }) );
        set("talk_reply","��...�p�S��...�A�ݪ��X�ڪ�[�~��]�� ?\n");
        set_skill("gun",100);
        set_skill("doubleshoot",100);
                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (:command("exert doubleshoot"):),
                (:command("reload clip"):), 
 }) );
set("inquiry",([
  "�~��" : "�s...�A�S�ݨ�~������[�Ǫ�]�ܡC\n",
  "�Ǫ�" : "����...�O�ʦ~�e������[�S���D�]]..",
  "�S���D�]" : "�]�������W���۳̧�����[�����]",
  "�����" : "���O�ڭ̯�������߳ǧ@��...�p�B��, �аݧA��[���U]�ڶ�?",
  "���U" : "�A�����ڮ��^�����W��������?",            
]) );

        setup();                
carry_object("/open/world3/super-light-area/weapon/wp/mag.c")->wield();  
carry_object("/open/world3/super-light-area/weapon/wp/mag_clip.c");
carry_object("/open/world3/super-light-area/weapon/wp/mag_clip.c");
carry_object("/open/world3/super-light-area/weapon/wp/mag_clip.c");
}
void init()
{
  add_action("do_say","say");
}
int do_say(string str)
{
 object npc = this_object();
  if(!str) str = "...";
  if(strsrch(str,"��")!=-1)
  {
  if(npc->query("open_war"))
  {
    command("say �ڡA�u�O�ӷP�§A�F�C");
    command("say �h�a...�ڷP���쥦���N�]�X�ӤF");
    command("say �n�p�ߥ������U��....");   
    command("addoil");
    return 0;
  }
    command("say �ڡA�u�O�ӷP�§A�F�C");
    new(__DIR__"killer")->move(__DIR__"../hide.c");  
    new(__DIR__"soldier")->move(__DIR__"../hide.c");
    new(__DIR__"soldier")->move(__DIR__"../hide.c");
    new(__DIR__"soldier")->move(__DIR__"../hide.c");
    new(__DIR__"soldier")->move(__DIR__"../hide.c");
    new(__DIR__"soldier")->move(__DIR__"../hide.c");
    new(__DIR__"soldier")->move(__DIR__"../hide.c");
    new(__DIR__"soldier")->move(__DIR__"../hide.c");
   new(__DIR__"soldier")->move(__DIR__"../hide.c"); 
command("say �h�a...�ڷP���쥦�w�g�]�X�ӤF");
 command("say �n�p�ߥ������U��....");   
command("addoil");
  npc->set("open_war",1);
 return 1;
  }
  return 0;
}

int accept_fight(object who)
{
        if(!is_fighting())
        {
                command("angry");
                        }
        return 0;
}
int accept_object(object who,object ob)
{
 object ic, npc=this_object();
        if(ob->name()!="�ͤƱ��")  return 0;
        else {
        message_vision("$N���F���D�@��$n�C\n",who,ob);
        destruct(ob);
        command("say �o�i�O���öQ�������I�I�o.....�o...");
        command("thank "+who->query("id"));
        command("say �o�u�O�ӷP�E�A�F�C");
        command("say �n�a�I���o�˧ڧ��}�o�X�Ӫ��ޥ��������A�n�F�C");
        ic=new(__DIR__"obj/ic");
        ic->move(who);
        set("chat_msg",({
        "���D���Ħa���D�G�ש�, �ש󮳦^�ӤF..\n",
        (:command("sob"):),            
        }) );
        set_temp("control",1);
      npc->delete("open_war");
        return 1;
        }
}
void reset()
{
        set("chat_msg",({
     "���D���D�G�u��..�o�i����~�n��...�v�C\n",
        }) );
        return;
}
void die()
{
        object ob;
        object data;      
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
     message("world:world3:vision",
HIG+"\n�i�a���ֳ��j"+HIW+"�a�U�����D�Q"+ob->name(1)+"�����F�I�I\n\n"+NOR,users());
           ob->add("popularity",1);
           data=new(__DIR__"obj/data.c");
   tell_object(ob,HIW"�A�q�������D���W���o��ƺ�!!(You Get The Data!!)\n"NOR);
           data->move(ob);
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");  
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");   
     message("world:world3:vision",
HIG+"\n�i�a���ֳ��j"+HIW+"�a�U�����ö�����X�ʲM���F�I�I\n\n"+NOR,users());
        ::die();
        return;
}
