#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIG"�p��"NOR,({"small fish","fish"}) );
        set("long",
 "�@���N�ݪ��X�ӭ��̤��@�ˡA���i�O�o�̪������J��I[give xxx to fish]\n"
);
        set("age",15);
        set("race","���~");
        set("level",15);
        set("attitude", "peaceful");
        set("gender", "�k��" ); 
        set("limbs", ({ "�Y��", "����", "����","�I��","�y��" }) ); 
        set("verbs", ({ "bite"}) ); 
        set("chat_chance",6);
        set("chat_msg",({
        "�p���۹D�G���೽������C....A_A..\n",
        (:command("sing"):),            
        }) );

        set_skill("unarmed",30);
        set_skill("dodge",22);
        setup(); 
        carry_object(__DIR__"obj/ticket");
}
int accept_object(object who,object ob)
{
        object x;
        if(ob->name() !="���֯�")  return 0; 
        else {
                
          if(this_object()->query_temp("call_boss")) 
          {
            command("say �Ѥj��X�ӭC....�A�n�䥦???"); 
            command("eh "+who->query("id"));
            return 0;
          }
        message_vision("$N���F�p���@�i$n�C\n",who,ob);
        destruct(ob);
        command("say �A���աI�I����...�n�a�I\n"); 
        command("nod "+who->query("id"));
        command("say ���ڴN�s�Ѥj�X�ӧa�C"); 
        message("world:world1:vision",HIG"\n\t�p�����ۡG�y���ﳽ�Ѥj�������z\n"NOR,users());
        x=new(__DIR__"fish-boss");
        x->move(environment(this_object()));
        set("chat_msg",({
        "�p���G����Ѥj�I..\n",
        (:command("kneel boss"):),            
        }) ); 
        set_temp("call_boss",1); 
        call_out("reborn",600);
        return 1;
        }

}

