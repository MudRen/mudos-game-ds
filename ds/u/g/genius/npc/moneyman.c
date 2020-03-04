#include <ansi.h>
inherit NPC;

void create()
{
        set_name( "活體保管箱", ({ "moneyman","man" }));
       set("long","一個很單純的人，但是身上好像帶著不少錢。\n");
        set("level",10);
        set("title",HIR"請向我要錢"NOR);
        set("gender", "男性");
        set("race", "human");
        set("age", 20);
                                        
        set("str",30);
        set("dex",30);
        set("con",10);
        set("int",30); 
        set("combat_exp",10000);
        set("evil",0);
        set_skill("unarmed",50);
        set_skill("combat",50);
        set_skill("dodge",50);

        set("attitude", "peaceful");
        set("inquiry/money", @LONG
我的主人說現在不知道如何讓我給錢
嗚嗚..壞主人....@@
LONG );
        setup();
        add_money("coin", 20000);
        add_money("dollar", 20000);
        carry_object("/open/world1/award/superpill");
carry_object("/open/world1/acme/area/npc/obj/god_pill"),2;
      carry_object("/open/world2/eq/life_glasses")->wear();
}
