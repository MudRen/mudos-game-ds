#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�°�",({"shi gi","shi","gi"}));
 set("long",@LONG
�L�N�O���F�����F��F�x��! ����@��, ���O�b��~�e�~��
�L����, �ܨ��H��������, ���L�̪���G���@�Ǩ�.....
LONG
     );
 set("nickname",HIG"�F��F�x"NOR);
 set("attitude","peaceful"); 
 set("age",49);
 set("gender","�k��");
 set("level",20);
 set("chat_chance",10);
set("chat_msg", ({" �°�ĤF�@�f����, �D: �o�i�����?......\n",
	          " �°�ĤF�@�f����, �D: �o�]���O, ���o�]���O, "+HIG+"Ŷ�ަ�"+NOR+"�u�O�O�H.....\n",
                            (:command("sigh"):),
 }));
	set("chat_chance_combat",200);

	set("talk_reply","�դU�i�H���b�U�@�Ӧ���?\n"NOR);

	set("inquiry/Ŷ�ަ�","�N�O�e��n�X����������, �����Q���ӲV�y�������Ѥj����, �o�U��ñ�X�����Q�L����.....\n"NOR);

	set("inquiry/ñ�X��","���O�o���n�X����������l, ��....\n");

	set("inquiry/���Q","�N�O���b���F�q���f�����ӽ��Y��!.\n"NOR);

 set("chat_chance_combat",20);
 setup();
 carry_object(__DIR__"eq/sea_cloth")->wear();
 carry_object(__DIR__"eq/gold_fur_boots")->wear();
}


void init()
{
       add_action("typenod","nod");
}
     int typenod(string arg)
{
        object me;
        me=this_player();
        if(arg != "shi gi" && arg != "shi" && arg !="gi") return 0;
        message_vision("�°򰪿�������$N����, �f�����D: �N�浹�դU�F...!\n\n",me);
        message_vision("�лդU���b�U����Q���^ñ�X��, �N�浹�դU�F...!\n\n",me);
        return 1;
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="ñ�X��")
        {
           command("? "+who->query("id"));
           return 1;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ЧA���@�U�C");
             return 0;
          }
	message_vision("$N���F�°�@�i"+ob->query("name")+"�C\n",who);
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
      object me,obj,item;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("get_paper");
      switch( i ) {
          case 1:
            command("jump");
            command("say �P�³o��S��!!");
            obj->set_temp("get_paper",i+1);
            call_out("get_paper",1,me);
            break;
          case 2:
            message_vision(YEL"�°򻡹D:�b�U�@�w���}���դU������!!�C\n"NOR,me);
         command("smile");
            obj->set_temp("get_paper",i+1);
            call_out("get_paper",1,me);
            break;
          case 3:
       tell_object(me,HIY"(�A���n��W�[�F!!)\n"NOR);
       me->add("popularity",1); //�n��
              obj->delete_temp("get_paper");
            break;
            }
                    
}


