#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�¦�ѤH" ,({ "old man","man" }) );
        set("level",55);
        set("race","�H��");
        set("gender","�k��");
        set("age", 90);
        set("long", "�L�O�@��l�˧��窺�¦�ѤH�C\n");
        set("int",100);
        set_spell("god-fire",100);
        set_spell("god-benison",100);
        set_skill("sword",120);
        set_skill("parry",100);
        set_skill("dodge",110);
        set_skill("godsword",110);
        set_skill("mirage-steps",100);
        set("chat_chance", 10);
        set("chat_msg",({
           (:command("exert mirage-steps"):),
           (:command("exert godsword"):),
        }) );
        set("chat_chance_combat",120);
        set("chat_msg_combat", ({
                  (:command("cast god-fire"):),
                  (:command("cast godbenison"):),
                  (:command("cast godbenison"):),
                  (:command("cast godbenison"):),
                  (:command("cast god-fire"):),
        }) );
        set("talk_reply","�A�����p�Ѩ�@�I�p��(help)�ܡH\n");
        set("inquiry/help","�A�Y���X�Ѧ��o������]�A�۵M���A���n�B�C\n");
        setup();
        add_money("coin",100);
        carry_object(__DIR__"wp/longsword.c")->wield();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="�]���]")
        {
           command("slap "+who->query("id"));
           command("say �A��ڬO�߯}�ꪺ�r�C....�]-.-�^�Y");
           return 0;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
message_vision("$N���F�¦�ѤH�@��"+ob->query("name")+"�C\n",who);
             command("hmm");
             obj->start_busy(10);
             obj->set_temp("giveplate",1);
             destruct(ob);
             call_out("giveplate",1,who);
             return 1;
        }
}
void giveplate()
{
      int i;
      object me,obj,plate;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("giveplate");
      switch( i ) {
          case 1:
            say(HIY"�¦�ѤH�J���@�F�@�o���p�]�l�C\n"NOR);
            obj->set_temp("giveplate",i+1);
            call_out("giveplate",3,me);
            break;
          case 2:
            command("say ��ӳo�p�F��N�O�ϱo�Ѧ��b�߶��o�����r�C");
            obj->set_temp("giveplate",i+1);
            call_out("giveplate",2,me);
            break;
          case 3:
            say(HIY"�¦�ѤH���۩]���]�b��W�⪱�A�ƬO�߷R�C\n"NOR);
            command("smile");
            obj->set_temp("giveplate",i+1);
            call_out("giveplate",3,me);
            break;
          case 4:
            command("say �Ѥҥͥ��̳��w���ìé_�j���F�A�o�����]�A���ͭȱo�ڡI");
            obj->set_temp("giveplate",i+1);
            call_out("giveplate",3,me);
            break;
          case 5:
            command("say �o�˧a�I�o�ӥO�P���A�C");
            command("say �H�ᦳ��x���A�i�G�X���O�P�A�O�H�]�ȷq�A�T���r�C");
            obj->set_temp("giveplate",i+1);
            call_out("giveplate",3,me);
            break;
          case 6:
            plate=new(__DIR__"obj/plate");
            plate->move(obj);
            command("give plate to "+ me->query("id") );
            obj->delete_temp("giveplate");
            break;
          }
}
