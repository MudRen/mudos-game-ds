#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name("���۴�",({"bad she bun","bun","she","bad"}));
       set("race","���~");
       set("level",20);
       set("age",10);      
       set("attitude","friendly");
       set("limbs", ({ "�Y��", "����", "����", "����"}) );
       set("verbs", ({ "bite"}) ); 
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "���۴�:���೽������C~~~~~"}));  
       set("long",@LONG      
���۴��A���s�̳̥��������A���٬O�}�A�b���Ѥj�����U�C

LONG
); 
        setup(); 
        carry_object(__DIR__"obj/ticket");
} 
