#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�f�H" , ({"patient"}) );
set("long", "�@�ӴX�Q�����Ѧ~�f�H�A�ݰ_�Ӧn���ܨ��W�C\n");       
        set("race", "�H��");
        set("age",70);        
        set("attitude", "friendly");
        set("level", 5);
        set("combat_exp",300); 
    set("chat_chance", 10 );  
  set("chat_msg", ({       
//     (: random_move :),
}) );
        setup();
        
}


