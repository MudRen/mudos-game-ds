#include <npc.h>
#include <ansi.h>

void create()
{
        set_name( "梅封" , ({ "mei feng","mei","feng"}) );
        set("long",@long
　　梅封為一個高瘦的壯年男子，手長過膝，提著一條四丈有餘的銀
鞭，穿著一件灰樸樸的衣裳，臉上頗有風塵之色，身上背著個包袱，
看起來不像是本地人，不知來這兒做什麼。
long
);
        set_race("strength");
        set("age", 35 );
        set_attr( "str" , 25 );
        set_skill( "whip" , 120);
        set_skill("dodge" , 100);
        set_skill("parry" , 100);
        set( "title" , "四丈銀鞭" );
        set("chat_chance", 5 );
        set("chat_msg", ({
			"梅封喃喃自語道：「想不到這廝這麼兇狠，憑我現在的本事還無法收服的了吧..」\n",
			"梅封望著天空嘆道：「我十年苦練，難道真報不了這個仇嗎....」\n",
			(: command("sigh") :),
        }));
        setup();
        set_level( 20 );
        carry_object(__DIR__"obj/silver-whip")->wield();
        carry_object(__DIR__"obj/grey-cloth")->wear();
		carry_object(__DIR__"obj/big-bag");
}

void exchange( object player , object ob )
{
	object item;
    destruct(ob);
	if( objectp( item=present( "_OBJ_ID_GREEN_BELT_" , player) ) ) {
		// 道謝了事
		command("thank");
	} else {
		// 送禮了事
		command("say 我將這條價值不菲的腰帶送給你當謝禮吧。");
		tell_room( player , "梅封從包袱中拿出一條翠綠色的腰帶送給了" + player->name() + "。\n" , player);
		tell_object( player ,  "梅封從包袱中拿出一條翠綠色的腰帶送給了你。\n" );
		item = new(__DIR__"obj/green-belt");
		if( !item->move(player) )
			item->move( environment(player) );
	}
}

int accept_object(object me, object ob)
{
      if( !ob->id("_MEI_FENG_QUEST_") || is_fighting() )  {
              do_chat((: command, "shake" :));
              return 0;
       }
       command("wa");
       command("say 這這...這...真是謝謝你幫了這個大忙...");
       do_chat(({ (: exchange,  me  , ob:) }) );
       return 1;
}

void relay_say(object ob, string arg)
{
        if( arg=="報仇")  {
              command("hmm");
              return ;
        }
}

