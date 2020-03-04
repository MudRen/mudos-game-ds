#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ѱ��j�p",({"cook"}) );

set("long",
"�A�ݤF�@�ݲ��e���p�v, �u���L�⤤����½��, ���e���j��\n"
"�A���԰ժ��T��, �A���T�ﲴ�e���o��p�v�P��ܨ�, �]��\n"
"��P��p���]�O�@�����`���ǰݡC\n",
);
        set("age",40);
        set("race","�H��");
        set("level",12);
        set("attitude", "peaceful");
        set("gender", "�k��" );
        set("chat_chance",6);
        set("chat_msg",({
        "�ѱ��j�p�ۨ��ۻy����: �_�ǤF....��a�|����? \n",
        (:command("sigh"):),            
        "�ѱ��j�p�S���ۻy����: ����"HIY"��"NOR"�쩳�b��?\n" ,
        }) );
        set_skill("unarmed",20);
        set_skill("sword",10);
        setup();
}
int accept_object(object who, object ob)
{
        object pill;

        if(ob->name()!="����")  return 0;
        else {
                
          if(this_object()->query_temp("give_pill")) 
          {
            command("say �x?! ��a�٦��@���p�Ψ�??");
            command("? "+who->query("id"));
            command("say ...");
            return 0;
          }

        message_vision("$N���F�j�p�@��$n�C",who,ob);
        destruct(ob);
        command("say ��...�p�Ψ�A�i�^�Ӱ�!!!");
        command("thank "+who->query("id"));
        command("say ���°�! ��ڪ��p�Ψ�a�^�ӤF! �o�������N�e�A�a�C");
        pill=new(__DIR__"obj/int_pill");
        pill->move(who);
        set("chat_msg",({
        "�j�p��p�λ��D�G�A�`��^�Ӱ�..\n",
        (:command("jump"):),            
        }) );
        set_temp("give_pill",1);
        call_out("delay",600,this_object());
        return 1;
        }

}

void delay(object kore)
{
        if(!kore) return;
        kore->set_temp("give_pill",0);
        kore->set("chat_msg",({
        "�ѱ��j�p�ۨ��ۻy����: �_�ǤF....��a�|����? \n",
        (:command("sigh"):),            
        "�ѱ��j�p�S���ۻy����: ����"HIY"��"NOR"�쩳�b��?\n"
        }) );
        return;
}
