#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���W",({"wang-lou","wang","lou"}));
 set("long","�L�O�b�o���l�̳̦n��´�֤H�C\n");
 set("age",43);
 set("gender","�k��");
 set("level",20);
 set("title","´�ְ���");
 set_skill("parry",50);
 set_skill("dodge",50);
 set("chat_chance",20);
 set("chat_msg", ({"���W���_�⤤�����֭��n�ĤF�@�f��.\n",
                   (:command("sigh"):),
 }));
set("chat_chance_combat",200);
 set("talk_reply","�A�����ѤҤ@�I��(help)��?\n");
 set("inquiry/help","�A�Y����ǻ���������, �ګK´�@�i���n���A.\n");
 set("chat_msg_combat",({                         
                         (:command,"say �A�Ӥp�ݧڤF!!":),
 }));
 setup();
}


int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "fox fur")
        {
           command("slap "+who->query("id"));
           command("say �A���ڳo�ӬOԣ��....-.-");
           return 0;
	}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
             message_vision("$N���F���W�@�i "+ob->query("name")+"�C\n",who);
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
            say(HIY"���W�N�F�N�o�i���֡C\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 2:
            command("say �N...�N�O�o�i��...�Ӧn�F....");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 3:
            say(HIY"���W���_���֦b��l�W�_�_�ӤF�C\n"NOR);
            command("sweat");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            say(HIY"�L�F�@�|���W��W�K�h�F�@�i���n�C\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 5:
            command("say �Ѥҧ⨺�i���֪��@�������F�@�i���n, �K�e���A��S�ҧa");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 6:
            plate=new(__DIR__"obj/hat");
            plate->move(obj);
            command("give mask to "+ me->query("id") );
            say(HIY"���W���F�@�i���n�C\n"NOR);
            obj->delete_temp("givehat");
            break;
          }
}

