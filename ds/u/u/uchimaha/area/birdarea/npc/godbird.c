#include <ansi.h>
inherit NPC;
void create()
{
 set_name("����",({"god bird","god","bird"}));
 set("long","�L�O�ǻ������j���A�S�H������e�q��B�ӡA�]�S
�H���D�e�O���س��A�j�a�u�]���e�������_�S�B��
�����j�A�ӵ��L�@�Ӻٸ������������A�L�ݰ_�Ө{
�l�j�F�A�ǻD���L���w�Y�@�غ�⪺�p�ΡC\n");
 set("age",235);
 set("race", "���~");
 set("level",30);
 set("title","�ǻ�����");
 set("limbs", ({ "�Y��", "����", "�ͻH", "�}", "����" }) );
 set("verbs", ({ "bite", "claw" }) );
 set("evil",-50);
 set("dodge",70);
 set("parry",70);
 set("chat_chance",10);
 set("chat_msg", ({"�����{�l�B�P�B�P���T�F�_��~~~~~~\n",
 }));
 setup();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "green worm")
        {
           command("slap "+who->query("id"));
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �T�T�A�T�T�T�T�s�s�s���ڥ��b���A�ЧA���@�U���C\n");
             return 0;
           }
             message_vision("$N���F�����@�� "+ob->query("name")+"�C\n",who);
             command("lick");
             obj->start_busy(6);
             obj->set_temp("giveworm",1);
             destruct(ob);
             call_out("giveworm",1,who);
return 1;
        }
}
void giveworm()
{
      int i;
      object me,obj,worm;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("giveworm");
       if( !me || environment(me) != environment(obj) )
        {
                command("say �s�s�s�s�s�H�H���x�H" + RANK_D->query_respect(me) + "�H�O�H�H��");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"�����i�j�F���@�F�@�o���ΡC\n"NOR);
            obj->set_temp("giveworm",i+1);
            call_out("giveworm",3,me);
            break;
          case 2:
            command("say �s�s�T�T���N�O�o���Ρ��C");
            obj->set_temp("giveworm",i+1);
            call_out("giveworm",2,me);
            break;
          case 3:
            say(HIY"�����@��Y�۳o���ΡB�@��ܰ������ݵۧA�C\n"NOR);
            command(":)");
            obj->set_temp("giveworm",i+1);
            call_out("giveworm",3,me);
            break;
          case 4:
            say(HIY"�����b��}���F½��䪺�n���b��M����C\n"NOR);
            obj->set_temp("giveworm",i+1);
            call_out("giveworm",3,me);
            break;
          case 5:
            command("say �s�s���T�T���o�Ӱe���A���C");
            obj->set_temp("giveworm",i+1);
            call_out("giveworm",3,me);
            break;
          case 6:
            worm=new(__DIR__"obj/fur2");
            worm->move(obj);
            command("give fur to "+ me->query("id") );
            obj->delete_temp("giveworm");
            break;
          }
}

