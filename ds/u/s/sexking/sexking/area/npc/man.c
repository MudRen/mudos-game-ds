#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ۼ��O�h",({ "man","man" }));
        set("long",
        "�L�O�@��饻�ۼ��O�h�A�����Q���e�j�A�n���H�ɥi�H�����A�C\n"
        );
        set("age",50);
        set("level",20);
        set("gender", "�k��");
        set("str",50);                  
        set("dex",20);                  
        set("con",50);                
        set("int",20); 
        set("exp",5421);                
        set("attitude", "peaceful");
        set("combat_exp",2000);         
        set_skill("unarmed",60);   
        set_skill("parry",60);          
        set_skill("dodge",10);  
        set_skill("perception",10);
        set_skill("combat",50);        
        set("talk_reply","�Ӱ��ۼ��a...�Y�D�@�I...�H�H�H�C");
        set("chat_chance",8);
        set("chat_msg", ({
  name()+"���D�G�H�ʹN�O�Y�Y�Y�C\n",
  name()+"���D:�p�l!�A�n���ڦn�Y���F���? �C\n",
(: command("hoho") :),
(: command(":)") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
        "�ۼ��O�h�⨭���L�ӷQ����A�C\n",
         (: command("angry") :),
    }) );
        setup();
       carry_object(__DIR__"item/boil");
       }
void die()
{
        message_vision("$N�{���e�j�n����:���٨S�Y��ѤU�����ڡ�\n",this_object());
        ::die();
}
int accept_object(object who, object ob)
{
        object sex,a,ll,me;
        sex = this_object();
        me = this_player();
        ll =new(__DIR__"lobser");
        if( ob->query("id")!="lobser" || query_temp("lobser") ) return 0;
        message_vision(HIG"�ۼ��O�h�Y�媺��:�z�I�o���D�N�O�ǻ����̦n�Y��"HIR"�s��"NOR"?\n"NOR,me);
        command("say ���°�!");
        me->start_busy(2);
        set_temp("lobser",1);
        call_out("wa",3,me);
        call_out("wa2",5,me);
        call_out("ya",7,me);
        call_out("delay",600,this_object());
        set("chat_chance", 10);
        set("chat_msg", ({
  name()+"���������D�G�s���u�n�Y�C\n",
  name()+"���q���^���ۦY�s�����ַP! �C\n",
(: command("hoho") :),
(: command(":)") :),
}) );
return 1;
}
void wa(object me)
{
     if(!me) return;
     message_vision(HIG"�ۼ��O�h��M�q�I�᮳�X�F�@�����C\n"NOR,me);
     return;
}
void wa2(object me)
{
     if(!me) return;
     message_vision(HIY"�ۼ��O�h��_"HIR"�s��"NOR"�N�F�@�N..�@�f��|�F�U�h�C\n"NOR,me);
     return;
}
void ya(object me)
{
     if(!me) return;
     message_vision(HIY"�ۼ��O�h��������:�n�Y!�n�Y!�u�n�Y!���§A��!�C\n"NOR,me);
     this_player()->add("popularity", 2);
     set_temp("lobser",1);
     tell_object(this_player(),HIM"�ѩ�A���F�ۼ��O�h�@�Ӥj���ҥH�o��F 2�I�n��C\n"NOR);

     return;
}
void delay(object sex)
{
delete_temp("lobser");
set("chat_chance",8);
 set("chat_msg", ({
  name()+"���D�G�H�ʹN�O�Y�Y�Y�C\n",
  name()+"���D:�p�l!�A�n���ڦn�Y���F���? �C\n",
(: command("hoho") :),
(: command(":)") :),
}) );
        return;
}

        


