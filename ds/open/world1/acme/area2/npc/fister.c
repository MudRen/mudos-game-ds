#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "鬼拳無恨", ({ "ghost fister","ghost","fister" , "__GUARD__"}) );
        set("level",24);
           set("combat_exp",2400);
set("exp",1000);
        set("long","他是幽冥地窖中的鬼拳，拳法亦已到了出類拔萃的竟界。\n");
        set("evil",40);
        set("age",45);
        set("gender","男性");
        set("title",CYN"鬼出神沒"NOR);
        set("attitude","killer");
            set_skill("unarmed",48);
            set_skill("dodge",48);
           set_skill("parry",48);
        setup();
        carry_object(__DIR__"wp/fist.c")->wield();
}
