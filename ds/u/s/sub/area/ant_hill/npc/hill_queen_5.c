#include <ansi.h>
inherit NPC;

void create()
{
        set_name("蟻后", ({"queen ant","queen","ant"}) );
        set("long",@LONG
這是一隻蟻后，牠正在努力地繁衍後代。由於牠的身軀相當肥大，所
以行動相當的不方便。
LONG);
        set("unit","隻");
        set("race", "beast");
        set("gender","雌性");
        set("limbs", ({ "頭部", "身體", "觸角"})); 
        set("verbs", ({ "bite","claw","crash" })); 
        set("age", 1);
        set("level",5);
        set("max_hp",10000);
        set("hp",10000);
        set_temp("apply/hit",-10);      
        set_temp("apply/dodge",-40);
        set("str",3);

        setup();
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world2:vision", 
        "\n[0;1;36m [1m [1m[[1m�[1m�[1m�[1m�[1m�[1mY[1m�[1m�[1m�[1ms[1m�[1mD[1m][0m [0;1;33m�[1m�[1m�[1m�[1m�[1m�[1m�[1m}[1m�[1ma[1m�[1m�[1m-[1m-[1;31m�[1m�[1m�[1mZ[1;33m-[1m-[1m�[1mA[1m�[1mQ[0m"+HIW+ob->name(1)+"[0;1;33m�[1m�[1m�[1m�[1m�[1mF[1m�[1mC[0m\n\n"
        , users());
        ob->add("popularity", 7); //聲望
        ob=new_ob(__DIR__"obj/queen_head");
        ob->move(this_object());
        ::die();
        return;
}
