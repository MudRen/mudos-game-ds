#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�]��",({"god"}));
 set("long",@LONG
�N�O�]����
LONG
    );
 set("attitude", "peaceful");
 set("age",26);
 set("evil",-10);
 set("gender","�k��");
 set("level",9);
set("str",500);
 set_skill("hammer", 20);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}

int accept_object(object who,object ob)
{
        object obj,me;
      me=this_player();
        obj=this_object();
        if(ob->name()=="�O�X")
        {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �лդU�y�ݤ@�U...");
             return 0;
          }
	message_vision("$N���F�]���@��"+ob->query("name")+"�C\n",who);
	
             destruct(ob);
         command("smile");
            add_money("coin",50000);
            command("give 50000 coin to "+me->query("id"));
             return 1;
       }

     }


