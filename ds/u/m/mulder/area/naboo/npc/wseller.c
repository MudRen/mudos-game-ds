#include <path.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("�Z��������", ({ "weapon boss","boss" }) );
        set("gender", "�k��" );
        set("age", 22);
        set("long","�L�O�o�����E������,�A�L�H���Z�����ͪ��C\n");
       set("level",1);
        set("attitude", "friendly");
        set("chat_chance", 1 );    
        set("chat_msg", ({    
        (:command("say �R�h�I.........�R�h�I"):), 
        (:command("grin"):),
        (:command("say �����ȤF$$$$$$$"):), 
      (:command("say ��.....��......��"):),
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

