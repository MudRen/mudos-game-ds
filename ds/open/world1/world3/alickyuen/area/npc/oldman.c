#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�ѤH" , ({"oldman"}) );
set("long", "�@�Ӱ��֪��ѤH�A�L���b������ͬ��L�ݯf�C\n");       
        set("race", "�H��");
        set("age",80);  
        set("attitude", "friendly");
        set("level",10);
        set("combat_exp",300); 
    set("chat_chance", 10 );  
  set("chat_msg", ({       
//   (: random_move :),
}) );
        setup();
        
}


