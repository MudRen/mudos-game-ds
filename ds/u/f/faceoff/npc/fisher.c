#include <ansi.h>
inherit NPC;
void create()
{
 set_name("����",({"fisher"}));
 set("long",@LONG
�@�ӱ`�b�������Ȧ��X������, �ݰ_�Ӥ@�ƷT�ܭW�y��
�ˤl, ���G���ܦh���и�...
LONG
    );
 set("attitude", "peaceful");
 set("age",26);
 set("evil",-10);
 set("gender","�k��");
 set("level",9);
 set_skill("hammer", 20);
 set("chat_chance",10);
 set("chat_msg", ({"���ӹĤF�@�f����....\n",
		   "���ӷT�W������: �V�F�V�F....���"+HIY+"����"+NOR+"�u�O....\n",
 }));
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="����")
        {
           command("? "+who->query("id"));
           command("say �A���p���o�F�観�ζ�...?");
           return 0;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �лդU�y�ݤ@�U...");
             return 0;
          }
	message_vision("$N���F���Ȥ@��"+ob->query("name")+"�C\n",who);
             obj->start_busy(10);
             obj->set_temp("find_fish",1);
             destruct(ob);
             call_out("find_fish",1,obj);
             return 1;
        }

}

void find_fish()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("find_fish");
      switch( i ) {
          case 1:
            command("say ��! �o���׬O���p������...?");
            command("look "+ob->query("name")+" ");
            obj->set_temp("find_fish",i+1);
            call_out("find_fish",3,me);
            break;
          case 2:
            message_vision(YEL"$N�N��o����, ���o���ת��L�{�i�D���ȡC\n"NOR,me);
            obj->set_temp("find_fish",i+1);
            call_out("find_fish",3,me);
            break;
          case 3:
	    command("soga");
            command("say ��Ӧp��...�C");
            command("hoho");
	    obj->delete_temp("find_fish");
            break;
          case 4:
	    
            }
}