#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name("�}ù�h�L",({"kailo soldier","soldier"}));
       set("gender","�H��");
       set("level",30);
       set("age",30);      
       set("attitude","unfriendly");  
       set("evil",20);
       set("chat_chance", 4);
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "�}ù�h�L�j�ۡG�İڡI�I���r�I�I\n"}));
       set("long",@LONG      
�}ù�ꪺ�h�L�A�����B���C

LONG
); 
        setup();  
        carry_object(__DIR__"obj/sword")->wield();
} 

