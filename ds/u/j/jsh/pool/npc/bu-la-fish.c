#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name("�k�J��",({"bu la fish","fish"}));
       set("gender","���~");
       set("level",5);
       set("age",10);      
       set("attitude","friendly");
       set("limbs", ({ "�Y��", "����", "����", "����"}) );
       set("verbs", ({ "claw","bite"}) ); 
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "�k�J��:���೽�������~~~A_A~~~~\n" }) );
       set("long",@LONG      
�k�J���A�O�o�̳̽G�z�����A�ܦn�ۭt�C

LONG
); 
        setup(); 
        carry_object(__DIR__"obj/ticket");
} 

