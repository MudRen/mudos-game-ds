#include <ansi.h>
inherit NPC;
void create()
{
 set_name("��Ѥj",({"boat man","man"}));
 set("long","�L�O�L���q���߮�@�a����ҡC\n");
 set("age",41);
 set("gender","�k��");
 set("level",10);
 set("chat_chance",20);
 set("chat_msg", ({"��Ѥj��I�I����: ��S�}�O�Ѥl����? ���ت��N��Ѥl�F�W�@�[!.\n",
	           "��Ѥj��I�I����: �h�ݮ��F�q���t��l�̰�! �L����, �@�iñ�X���]�o���U��.\n",
                            (:command("pig"):),
 }));
	set("chat_chance_combat",200);

	set("talk_reply","����? �S�Ӥ@�өǦѤl��? �L����"+HIG+"�°�"+NOR+"......!\n"NOR);

	set("inquiry/�°�","�N�O���Ө���l! �ִ�����L��"+HIG+"Ŷ�ަ�"+NOR+", "+CYN+"�O���t��l�s���]�񤣥X�@��!\n"NOR);

	set("inquiry/Ŷ�ަ�","�N�O�o����ู��! �n���O���F�q����Y�ն���, ��|�s�@�i"+HIG+"ñ�X��"+NOR+""+HIG+"�]�o���X��?.\n"NOR);

	set("inquiry/ñ�X��","���]�O���F�q����H�o�X�Ӫ����F��! �����S���o������, �ڥ��O�¤ߧ��....\n");


 set("chat_msg_combat",({                         
                         (:command,"hmm":),
 }));
 setup();
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="ñ�X��")
        {
           command("? "+who->query("id"));
           return 0;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ЧA���@�U�C");
             return 0;
          }
	message_vision("$N���F��Ѥj�@�i"+ob->query("name")+"�C\n",who);
             obj->start_busy(7);
             obj->set_temp("get_paper",1);
             destruct(ob);
             call_out("get_paper",1,obj);
             return 1;
        }

}

void get_paper()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("get_paper");
      switch( i ) {
          case 1:
            command("wa");
            command("say �L������...�o�Oñ�X����!!");
            obj->set_temp("get_paper",i+1);
            call_out("get_paper",1,me);
            break;
          case 2:
            message_vision(YEL"��Ѥj��F$N�@��...�C\n"NOR,me);
         message_vision(YEL"��Ѥj���M���i�...�C\n"NOR,me);
         command("hoho");
            obj->set_temp("get_paper",i+1);
            call_out("get_paper",1,me);
            break;
          case 3:
       tell_object(me,"��Ѥj��A���D: �o�O�ڱq�n���a�Ӫ��_�s, �o�N�e���A�a...\n");
	p=new(__DIR__"obj/blood_horse");
        	p->move("/u/f/faceoff/area/seacoun42");
              obj->delete_temp("get_paper");
            break;
            }
             return 1;
}


