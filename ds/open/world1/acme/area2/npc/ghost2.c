#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "小鬼", ({ "little ghost","ghost", "__GUARD__" }) );
        set("level",20);
           set("combat_exp",2000);
set("exp",1000);
        set("long","他是一隻鬼頭鬼腦的小鬼，眼睛不停的骨溜溜的轉動。\n");
        set("age",12);
        set("evil",30);
set("title",CYN"鬼出神沒"NOR);
        set("gender","男性");
        set("attitude","killer");
            set_skill("unarmed",40);
        set_skill("dodge",40);
           set_skill("parry",40);
        setup();
}
