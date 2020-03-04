#include <path.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("武器店老闆", ({ "weapon boss","boss" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long","他是這暑店舖的老闆,，他以售賣武器為生的。\n");
       set("level",1);
        set("attitude", "friendly");
        set("chat_chance", 1 );    
        set("chat_msg", ({    
        (:command("say 買多點.........買多點"):), 
        (:command("grin"):),
        (:command("say 今天賺了$$$$$$$"):), 
      (:command("say 錢.....錢......錢"):),
}) );
	set("sell_list",([
		__DIR__"wp/lasergun" : 10,
		__DIR__"wp/laserclip" : 10,
		__DIR__"wp/lasersword":10,
		__DIR__"wp/hlasersword":10,
		__DIR__"wp/gpistol":10,
		__DIR__"wp/gclip":10,
		        ]) );
        setup();
}
void init()
{
	add_action("do_buy","buy");
	add_action("do_list","list");
	add_action("do_sell","sell");
}

