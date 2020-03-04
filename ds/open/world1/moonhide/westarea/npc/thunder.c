#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIC"艾涅爾"NOR, ({ "ai-nieer thunder", "thunder"}) );
        set("level", 55);
        set("long",@LONG
艾涅爾是九天雲魂的領主，擁有控制雷雲的能力，
傳聞他不是凡人，而是電神轉世的。
LONG
		);
        set("age", 40);
        set("attitude", "aggressive");
        set("title", HIY"雷神"NOR);
        set("chat_chance", 50);
        set("chat_msg", ({
           (: random_move :),
        }) ); 
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	        (: command("wield sword") :),  
    	    (: command("wield sword") :),        }));         
		setup();
        set_living_name("westwar");
        carry_object(__DIR__"obj/sword")->wield();
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
        ob->add("popularity", 3); 
        tell_object(ob,HIW"(你得到 3 點聲望。)\n"NOR);
        ::die();
        return;
}

