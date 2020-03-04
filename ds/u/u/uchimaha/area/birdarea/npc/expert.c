#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�q�۱M�a",({"stone expert","expert"}));
 set("long","�L�O�@��M����s�q�۪��H�C\n");
 set("age",33);
 set("gender","�k��");
 set("level",20);
 set_skill("parry",50);
 set_skill("dodge",50);
 set("chat_chance",10);
 set("talk_reply","�p�G�A������q�۪���, �ڥi�H�K�O���A���R��...:D\n");
 set("chat_msg", ({"�q�۱M�a���b�V�O�����q�ۡA�o�X�}��~~~�}��~~~�}��~~~���n�T�C\n",
                   
 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({                         
                         (:command,"say �A�Ӥp�ݧڤF!!":),
 }));
 setup();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "iron stone")
        {
           command("slap "+who->query("id"));
           command("say �ڬO���q�ۡ��M�a��....");
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
             message_vision("$N���F�q�۱M�a�@�� "+ob->query("name")+"�C\n",who);
             command("think");
             obj->start_busy(10);
             obj->set_temp("givehat",1);
             destruct(ob);
             call_out("givehat",1,who);
return 1;
        }
}
void givehat()
{
      int i;
      object me,obj,plate;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givehat");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"�q�۱M�a�V�F�V�o�ӥ��Y�C\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 2:
            command("say ��....�o���Ӥ��O�K��....");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 3:
            say(HIY"�q�۱M�a�S�V�F�V�o�����Y�C\n"NOR);
            command("think");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            say(HIY"�q�۱M�a�n���o�{�F����A�������`�C\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 5:
            command("say �o�O�@���W�n�����K�ۡA�i�H���y�������Z���A�ڧ�L�ٵ��A�a�C");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 6:
            plate=new(__DIR__"obj/iron");
            plate->move(obj);
            command("give stone to "+ me->query("id") );
            obj->delete_temp("givehat");
            break;
          }
}

