#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name("�L��h�L",({"benin soldier","soldier"}));
       set("gender","�H��");
       set("level",25);
       set("age",30);      
       set("attitude","friendly");  
       set("evil",20);
       set("chat_chance", 7);
       set("chat_msg", ({
                        "�Q�Ѭݨ��@�Ӭ��k�I����ݤF�N�p�³ª��I\n"}));
       set("long",@LONG      
�}ù�����̡A�L��̭����h�L�C
LONG
); 
        setup();  
        carry_object(__DIR__"obj/fork")->wield();
} 

