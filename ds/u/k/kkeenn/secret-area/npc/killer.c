#include <ansi.h>
inherit NPC;
void create()
{
     set_name(HIY"�����]"NOR,({"yellow storm robot","robot"}) );
        set("long",@LONG
�@�ʦ~�e�A�Ѥ@�s�a�U���̳��y���ͤƬ�Ǯa�H���F�M�@�Ǥ����W��
����X�����Ǫ��A���Q�ѥ��Ӷ}�P�s�q�|�A�i�O�ѩ�䤤�@�Ӭ�Ǯa���]
�p���X�F�岫�A�ܦ��F�T��q��Ϊ��Ǫ��A���q�H�� �C
LONG
);
        set("title","�y���ѧ@�~�z");
         set("age",100);
         set("level",60);
         set("gender","����");
         set("max_hp",10200);
         set("hp",10200);
         set("race","human");
        set("talk_reply","�B��, �A�����ڱq���D���Ѽo�������o��ƺж�?\n");
        set("attitude", "peaceful");
       set_spell("summon_wind",100);
  set("chat_chance_combat", 100);       
  set("chat_msg_combat", ({
                (:command("cast summon_wind"):),
                 }) );
        set("chat_chance", 13);
        set("chat_msg",({ 
               (: random_move :),
        "�����]���|�P���_�F�������s�����H\n",
        "�����]��: �֯����ڥ����D�������Y�H\n",
        "�����]��: �֥i�H���ڸ�ƺ�, �ڥH��N���L�@�ԡC\n",
        "�����]��: �֯�⫰�D����ƺЮ����ڡH\n",
        "�����]���W������C�C�����o�X�ӡC\n",
        }));
          set("addition_armor",100);
          set("Merits/wit",3);
          set("addition_damage",50);
          add("apply/hit",50);

        setup();
}
int accept_object(object who,object ob)
{
        object ic, npc = this_object();
        if(ob->name()!="��ƺ�")  return 0;
        else {            
        message_vision("$N���F���ЩǤ@��$n�C\n",who,ob);
        destruct(ob);
        command("say �o�i�O�����o����ƺСI�I�o.....�o...");
        command("thank "+who->query("id"));
        command("say �o�u�O�ӷP�E�A�F�C");
        command("say �n�a�I���o�˧ڧ�ۤv���ޥ��������A�n�F�C");
        ic=new(__DIR__"obj/ic2");
        ic->move(who);
        set("chat_msg",({
        "���Щǰ����a���D�G�ש�, �ש�o��F..\n",
        (:command("ya"):),            
        }) );
        command("say �T�T~~�B��~~�ڭ̫�|�����C");
        command("wave");
        set_temp("control",1);
       destruct(npc);
        return 1;
        }
}
void reset()
{
        set("chat_msg",({
     "���Щǻ��D: �n�Q�n��....\n",
        }) );
        return;
}


void die()
{
        object ob;
        object control;
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
     message("world:world3:vision",
HIG"\n�i�a������j"+HIW"
�a�U���ʦ~��ê-"HIY"�����]"HIW"�Ѧb"+ob->name(1)+"����U�I�I\n\n"+NOR,users());
           ob->add("popularity",1);
  control=new(__DIR__"obj/control.c");
   tell_object(ob,HIW"�A�q�����]���W���o�ͤƱ��!!(You Get The Control!!)\n"NOR);
   control->move(ob);
        ::die();
        return;
}

