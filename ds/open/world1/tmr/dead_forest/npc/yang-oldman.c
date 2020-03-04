// 楊嘯之母 - 解七彩之矢Quest
#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
        set_name( "老婦人", ({ "old woman" , "woman" }) );
        set_race("human");
        set("age", 70);
        set("long",@long
    這是一位非常有精神的老婦人，但瞧她神情落漠，好像心底有什麼不
開心事兒難以開解。
long
        );
        set("chat_chance", 5 );
        set("chat_msg", ({
			(: command("sigh") :) ,
			(: command("glare") :) ,
        }));
        setup();
        carry_money("coin", 50);
}

int accept_object(object me, object ob)
{
	   if( ob->query_learn("rainbow arrow") ) return 0;
       if( !ob->id("_RAINBOW_ARROW_QUEST_") || is_fighting() ) {
              do_chat((: command, "say 你給我這個幹嘛？" :));
              return 0;
       }
    	me->set_temp( "quest-yang-xiao" , 3 );
		do_chat( ({
			"老婦人隨即將書信折開來，細細閱讀\.....\n" ,
			"眼見老婦人乾枯\的雙眼流出兩行眼淚\，顯見情緒非常的激動...\n" ,
			"老婦人手拿著書信，喃喃自語道：「想不到我的嘯兒尚在人世，我早就原諒他當年的離家出走了...」\n" ,
			"老婦人不停地低聲說道：「我已經原諒他了...我已經原諒他了...我已經原諒他了...」\n" ,
			(: tell_object , me , CYN"(你暗想應該要將這個好消息告訴楊嘯才是。)\n" NOR :) ,
			( : destruct , ob : ),
		}) );
       return 1;
}

void relay_say(object ob, string arg)
{
	object letter;
	// 已學得七彩之矢的人，則不必再解了
	if( ob->query_learn("rainbow arrow") ) return;
	if( arg=="楊嘯" ) {
		do_chat( ({
			 "老婦人嘶啞地嗓子問道：「剛剛是你提到我兒的名字嗎？這麼多年來老婦一直都沒有他的下落啊...」\n"
			 , (: command( "sob") :)
		 }) );
	return;
	}
}