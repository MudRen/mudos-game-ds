#include <ansi.h>
inherit NPC;
void create()
{
 set_name("����",({"sin pai","pai","sin"}));
 set("long",@LONG
�L�O�b��~�e�~�Q������L������F�x, ���L��ҫH����
�K�êk�߫o�b�u�u����~���������H�W���H��, �N�s�c�W
�L�������Q�b�L�����]�����F���Q��.
LONG
     );
 set("nickname",HIG"���F���x"NOR);
 set("attitude","peaceful"); 
 set("age",54);
 set("gender","�k��");
 set("level",20);
 set("chat_chance",10);
 set("chat_msg", ({"���񦣸L���ݵۤ���....\n",
 }));
 set("chat_chance_combat",20);
 setup();
 carry_object(__DIR__"eq/sea_cloth")->wear();
 carry_object(__DIR__"eq/big_pan")->wield();
 carry_object(__DIR__"eq/gold_fur_boots")->wear();
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="��Ʈv���x�L")
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
	message_vision("$N���F����@��"+ob->query("name")+"�C\n",who);
             obj->start_busy(7);
             obj->set_temp("find_mark",1);
             destruct(ob);
             call_out("find_mark",1,obj);
             return 1;
        }

}

void find_mark()
{
      int i;
      object me,obj,item;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("find_mark");
      switch( i ) {
          case 1:
            command("say ��! �o���O��Ʈv���x�L��?");
            command("say �o��"+RANK_D->query_respect(me)+"�O�q��o���x�L���H");
            obj->set_temp("find_mark",i+1);
            call_out("find_mark",1,me);
            break;
          case 2:
            message_vision(YEL"$N�N���o�x�L���L�{�i�D����...�C\n"NOR,me);
         command("sob");
            obj->set_temp("find_mark",i+1);
            call_out("find_mark",1,me);
            break;
          case 3:
	    command("nod");
            command("say ���̮Ʊo���Ʈv�����p���U��!!�C");
            command("sigh");
            obj->set_temp("find_mark",i+1);
            call_out("find_mark",1,me);
            break;
          case 4:
         command("say �P��"+me->query("name")+"�i���L���U��....");
          command("say �Ш����x�@��!");
          command("bow");
          command("say ���x�۷�[���W�q, ���P�դU�A�����S!");
       tell_object(me,HIY"(�A���n��W�[�F!!)\n"NOR);
       me->add("popularity",1); //�n��
              obj->delete_temp("find_mark");
            break;
            }
                    
}

