#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�޲z��", ({"manager"}) );
	set("long", "�@�Ӻ޲z���A�t�d�޲z���������u�@�C\n");
	set("race", "�H��");
	set("age", 40);
	set("level", 15);
        set("chat_chance",4);
        set("chat_msg",({
        (:command("sigh"):),            
        }) );
	setup();
}
void init()
{       

        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
add_action("do_nod","nod");
}
int do_nod(string arg)
{
      object me;
      me=this_player();
          if(!me->query_temp("gived_key")) return 0;
 {
        command("say �A�����ڧ�Ӥp�ĶܡH�L�w���ܤF�ƤѤF�A�Ʊ�L�S���h......");
}
}
int accept_object(object who,object ob)
{
        object key;
        if(ob->name()!="�_��")  return 0;
        else {
                
          if(this_object()->query_temp("give_key")) 
          {
            command("say �ڤw���F�_�ͤF......");
     //       command("? "+who->query("id"));
            return 0;
          }    
        message_vision("$N���F�޲z���@��$n�C\n",who,ob);
        destruct(ob);
        command("thank "+who->query("id"));
message_vision("�޲z���ǰe�F�������ӳ�쪺�q�l���h$N����f���C\n",me);
who->receive_money(100);
        command("hmm");
        command("say �h�§A���ڧ�^�o���_�͡A�аݧA�����h�ڤ@�Ӧ��ܡH");
        set_temp("give_key",1);
who->set_temp("gived_key",1);
        call_out("delay",1200,this_object());
        return 1;
        }

}
void greeting()
{
object me;
me=this_player();
          if(!me->query_temp("go_child")) return 0;
 {
command("say ���F�L�ܡH");
tell_object(me,"�A��p�Ī����B�a�I�@���@�Q�������޲z��ť�C\n");
tell_object(me,"�A��M�o�{�ۤv���Y���M�g��W�i�F�C\n");
me->add("exp",1000);
me->delete_temp("go_child");
}
}
void delay(object manager)
{
        if(!manager) return;
        manager->set_temp("give_key",0);
        return;
}