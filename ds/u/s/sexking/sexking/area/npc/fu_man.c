#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�߮���H",({ "fu shun lan man","fu","man" }));
        set("long",
                "�L�O�@��߮�y�������H�A���w�_�I�A�ߺD�ΤM�A�B�ܦ�����C\n"
                
        );
        set("age",41);
        set("level",20);
        set("gender", "�k��");
        set("str",30);                  
        set("dex",40);                  
        set("con",40);                
        set("int",30); 
        set("exp",3117);       
        set("attitude", "peaceful");
        set("combat_exp",2000);         
                        

        set_skill("throwing",10);    
        set_skill("parry",20);          
        set_skill("dodge",50); 
 set_skill("blade",50);
        set_skill("combat",50);        
        
        set("talk_reply","�԰��A�O�Z�h���ͩR�A��ۤv�ޤ��p�H�ɡA�Z�h���|�帡�۱��A�H�D�L�Y�C");

        set("chat_chance",5);
        set("chat_msg", ({
  
  name()+"�����D�G�߮���H��̱j���H�åЫ۪šA�ڬO�@���l�]�l���W�r�C\n",
  name()+"�}�l���ʪZ�h�M�m�M�C\n",
  name()+"���_�Z�h�M����L���A�I�w�M�k�C\n",
(: command("think") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
              "���H�E�ʪ���q�G�ݧڥΧڪ��M���F�A�I�I\n",
         (: command("baga") :),
    }) );
        setup();
        carry_object(__DIR__"eq/rattan_leggings");
        carry_object(__DIR__"wp/japen_blade");
}
void die()
{
        message_vision("$N�ӻ{���ѡA���_��W���M�A��J�ۤv���������A�˦b�a�W�A�@�ʤ]���ʤF�C\n",this_object());
        ::die();
}
