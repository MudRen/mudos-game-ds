//updated
#include <ansi.h>
inherit NPC;
void create()
{
	set_name(RED"�s�O"NOR, ({"bartender"}) );       
	set("long", "�@�Ӱs�O,�t�d�ݦu�o���s�a��,���W�S�X���w�����A�C\n");
	set("race", "�H��");
	set("age", 40);
	set("level", 5);
        set("chat_chance",6);
        set("chat_msg",({
        (:command("sigh"):),            
        }) );
                set("talk_reply","�A�����ڤ@�I�p��(help)�ܡH\n");
                set("inquiry/help","�o�X�Ѫ����s������F,�n�G�C�C\n");
	setup();

}
int accept_object(object who,object ob)
{
        object bottle;

        if(ob->name()!="���s")  return 0;
        else {
                
          if(this_object()->query_temp("give_bottle")) 
          {
            command("say �ڤw�����������s�F...�h��....");
            command("? "+who->query("id"));
            command("say �A�٬O�ۤv�d�۳ܧa...");
            return 0;
          }    
        message_vision("$N���F�s�O�@��$n�C",who,ob);
        destruct(ob);
        command("say �h�§A�e�ڬ��s��...���M�ڤ����Ȥ֫ܦh��...");
        command("thank "+who->query("id"));
        command("hmm");
        command("say �ګe�Ӥ��˨���_�۴N�e���A�a�C");
        bottle=new(__DIR__"obj/crystal");
        bottle->move(who);
        set("chat_msg",({
        "�s�O���D�G�٦n�A�����s��F..\n",
        (:command("grin"):),            
        }) );
        set_temp("give_bottle",1);
        call_out("delay",1200,this_object());
        return 1;
        }

}
void delay(object bartender)
{
        if(!bartender) return;
        bartender->set_temp("give_bottle",0);
        bartender->set("chat_msg",({
        (:command("sigh"):),            
        }) );
        return;
}
