#include <ansi.h>
inherit NPC;
void create()
{
        set_name("練習生",({ "trainee" }) );
        set("long",@LONG
這裡的練習生, 都是王府招收神木村裡的青年好手, 看他們一個個
體型強壯, 努裡練武的情形, 使你不竟在旁觀看.
LONG    
);
        set("race","人類");
        set("age",25);
        set("level",18);
        set("attitude","friendly");
        set_skill("dodge",30);
        set_skill("unarmed",50);
        set_skill("parry",20);
         setup();
        
}

