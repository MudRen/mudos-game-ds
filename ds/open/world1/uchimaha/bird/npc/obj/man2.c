#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���_",({"chen bow","chen","bow"}));
 set("long","�L�O�y����������, �L�ݰ_�Ӧ��G���Ƿдo�C\n");
 set("age",60);
 set("gender","�k��");
 set("level",20);
 set("title","�y��������");
 set_skill("parry",50);
 set_skill("unarmed",50);
 set_skill("dodge",50);
 set("chat_chance",10);
 set("chat_msg", ({"���_�C�n���ۨ��ۻy:����...�쩳�ӫ���....\n",
                   (:command("sigh"):),
 }));
 set("chat_chance_combat",10);
 set("talk_reply","�A�����ѤҤ@�I��(help)��?\n");
 set("inquiry/help","�ЧA���ڧ�^�Ѫ����֡A���O�ڪ��Ǯa�_�A�аȥ��n��^�ӡC\n");
 set("chat_msg_combat",({                         
                         (:command,"say �A�Ӥp�ݧڤF!!":),
 }));
 setup();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "skydog fur")
        {
           command("slap "+who->query("id"));
           command("say �o�O���̪F�F��....-_-");
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
           if( present("godwind bag", who) )
           {
             command("?");
             return 0;
           }

             message_vision("$N���F���_�@�i "+ob->query("name")+"�C\n",who);
             command("think");
             obj->start_busy(6);
             obj->set_temp("givebag",1);
             destruct(ob);
             call_out("givebag",1,who);
return 1;
        }
}
void givebag()
{
      int i;
      object me,obj,wind;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givebag");
      switch( i ) {
          case 1:
            say(HIY"���_�J���@�F�@�o�i�֡C\n"NOR);
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 2:
            command("say �Ӧn�F�A�N�O�o�i�֡C");
            obj->set_temp("givebag",i+1);
            call_out("givebag",2,me);
            break;
          case 3:
            say(HIY"���_�ˤF�˳o�i�֨åB��:�ڦ��ӪF��n�e�A�A�A�����C\n"NOR);
            command("dance");
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 4:
            say(HIY"���_�b���Ǫ��c�l���F½��䪺�A�����D�L�b�䤰��F��C\n"NOR);
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 5:
            command("say �o�O�ڿ˦۰����U�l�A�K�e���A��@�S�ҧa�C");
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 6:
            wind=new(__DIR__"obj/bag");
            wind->move(obj);
            command("give bag to "+ me->query("id") );
            wind->set("no_give", 1);
            obj->delete_temp("givebag");
            break;
          }
}

