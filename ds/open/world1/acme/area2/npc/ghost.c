#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "厲鬼", ({ "warrigal ghost","ghost", "__GUARD__" }) );
        set("level",24);
           set("combat_exp",2400);
set("exp",1000);
        set("long","他是一隻全身穿著紅色的女鬼。\n");
        set("age",30);
        set("evil",30);
set("title",CYN"鬼出神沒"NOR);
        set("gender","女性");
        set("attitude","killer");
            set_skill("unarmed",48);
          set_skill("dodge",48);
           set_skill("parry",48);
        setup();
}
