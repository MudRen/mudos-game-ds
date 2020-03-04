#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���A",({"chiu gin","chiu","gin"}));
 set("long","�o�O�b�y�������i�H����W�B�����Ѥ~´���֤k�C\n");
 set("age",17);
 set("gender","�k��");
 set("level",7);
 set("title","´���֤k");
 set_skill("parry",10);
 set_skill("dodge",10);
 set("chat_chance",10);
 set("chat_msg", ({"���A���ۻ��D:���S���H�۫H��....\n",
                   (:command("cry"):),
                   (:command("sob"):),
 }));
 set("chat_chance_combat",200);
 set("talk_reply","�A�����ڤ@�I��(help)��?\n");
 set("inquiry/help","���n������, �D�֤񪰥֧�n, ���O�b�������H������
�H��....�A�����ڮ��i�n�D�֨Ӷ�? �ڭn�ҩ����L�̬�!\n");
 setup();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "snake fur")
        {
           command("say ���O�o��....");
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
             message_vision("$N���F���A�@�i "+ob->query("name")+"�C\n",who);
             command("bow");
             obj->start_busy(10);
             obj->set_temp("givefur",1);
             destruct(ob);
             call_out("givefur",1,who);
return 1;
        }
}
void givefur()
{
      int i;
      object me,obj,fur;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givefur");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"���A�@�F���o�i�D�֡C\n"NOR);
            obj->set_temp("givefur",i+1);
            call_out("givefur",3,me);
            break;
          case 2:
            command("say �o�i�D�֬O�W�W����, �i�H´�X�ܦn���F��ӡC");
            command("smile");
            obj->set_temp("givefur",i+1);
            call_out("givefur",2,me);
            break;
          case 3:
            say(HIY"���A����и�, ���̶ǥX´�������B���n�C\n"NOR);
            obj->set_temp("givefur",i+1);
            call_out("givefur",3,me);
            break;
          case 4:
            say(HIY"�L�F�@�|���A�q�и̨��X, ��W���ۤ@���@��C\n"NOR);
            obj->set_temp("givefur",i+1);
            call_out("givefur",3,me);
            break;
          case 5:
            command("say �ڥΤ@�������D�ְ��X�F�@���@��, �N��O���A������§�a�C");
            obj->set_temp("givefur",i+1);
            call_out("givefur",3,me);
            break;
          case 6:
            fur=new(__DIR__"obj/hands");
            fur->move(obj);
            command("give hands to "+ me->query("id") );
            obj->delete_temp("givefur");
            break;
          }
}

