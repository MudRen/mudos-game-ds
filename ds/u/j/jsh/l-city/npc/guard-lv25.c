#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name("�}ù����",({"kailo guard","guard"}));
       set("gender","�H��");
       set("level",25);
       set("age",30);      
       set("attitude","friendly");  
       set("evil",20);
       set("chat_chance", 7);
       set("chat_msg", ({
                        "�}ù���û��G�����H���I�I���o�i�J�I�I�A�Q��ڭ̾Ԫ����I\n"}));
       set("long",@LONG      
��u�۶}ù�����������A�����~�~�����C
LONG
); 
        setup();  
        carry_object(__DIR__"obj/axe")->wield();
} 

