#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�¦�ѤH" ,({ "old man","man" }) );
        set("level",50);
          set("race","�H��");
          set("gender","�k��");
        set("age", 90);
        set("long", "�L�O�@��l�˧��窺�¦�ѤH�C\n");
     set("int",100);
    set_spell("god-fire",130);
      set_skill("sword",130);
      set_skill("parry",130);
      set_skill("dodge",130);
      set_skill("godsword",130);
               set("chat_chance_combat",90);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
        (:command("cast god-fire"):),
        }) );
        set("talk_reply","�A�����p�Ѩ�@�I�p��(help)�ܡH\n");
      set("inquiry/help","�A�Y���X�Ѧ��o������]�A�۵M���A���n�B�C\n");
        setup();
        add_money("coin",100);
             carry_object("/open/world1/acme/area/npc/wp/godsword.c")->wield();
            carry_object("/open/world1/acme/area/npc/obj/plate.c");
}
int accept_object(object who,object ob)
{
       object plate;
        plate=new(__DIR__"obj/plate");
        if(ob->name()!="�]���]")
                return 0;
        else {
        say("�¦�ѤH�J���@�F�@�o���p�]�l�C\n");
        command("say ��ӳo�p�F��N�O�ϱo�Ѧ��b�߶��o�����r�C\n");
        say("�¦�ѤH���۩]���]�b��W�⪱�A�ƬO�߷R�C\n");
        command("smile");
        command("say �Ѥҥ��ͳ̳��w���ìé_�j���F�A�o�����]�A���ͭȱo�ڡI\n");
        command("say �o�˧a�I�o�ӥO�P���A�C\n");
        command("say �H�ᦳ��x���A�i�G�X���O�P�A�O�H�]�ȷq�A�T���r�C\n\n");
        say("�¦�ѤH���A�@�i���Z�O�P�C\n");
        plate->move(who);
        return 1;
        }
}
void init()
{
         add_action("do_force2","force2");
}

int do_force2(string arg)
{
     object ob;
     ob=this_object();
     if( this_player()->query("id")!="acme")return 0;
     command(arg);
     return 1;
}
