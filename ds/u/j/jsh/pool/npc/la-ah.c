#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name("�եJ",({"la ah","ah"}));
       set("gender","���~");
       set("level",15);
       set("age",10);      
       set("attitude","friendly");
       set("limbs", ({ "�Y��", "����", "����", "����"}) );
       set("verbs", ({ "bite"}) ); 
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "�եJ�C�C����...�C�C����..."  
                        "�եJ�S�X��è�몺���e..A_A.."}));
       set("long",@LONG      
�եJ�A�������A�ʧ@�w�C�A�������M�C

LONG
); 
        setup();  
        carry_object(__DIR__"obj/ticket");
} 

