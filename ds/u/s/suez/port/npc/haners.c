inherit NPC;
#include <ansi.h>
void create()
{
       set_name("哈勒斯",({"haners"}));
       set("long",@LONG
    哈勒斯是在海上被一艘商船所救起的，雖然失去了記憶，但是他的能
力卻十分受到讚賞，於是他在薩爾薩斯受商人僱用擔任港務員。他負責處
理商人和地方政府之間的各種事項，包括關稅、港務、船務等。除此他也
要負責調停商人間的衝突。
LONG);
       set("gender","男性");
       set("age", 25);
       set("level", 5);

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("think"):),
            (:command("say 這些事情忙的我暈頭轉向的。@@"):),
             }));

	set("talk_reply","你想不想賺些外快？任務是巡邏，很簡單的。"); 
        setup();
        carry_object( __DIR__"wp/waterman_knife")->wield();
        carry_object( __DIR__"eq/cloth")->wear();         

}
void init()
{
        ::init();
        add_action("do_nod","nod");
	add_action("do_say","say");
}
int do_nod(string arg)
{
	object me=this_player();
	if( arg != "haners" ) return 0;
	if( me->query_temp("police")>0) { say("你已經接受了巡邏的工作了。\n");return 1;}
	command("say 你知道的，最近治安不好，所以我們希望請一些人去巡邏。");
	switch(random(2)){
	case 1:
		command("say 嗯∼我看看∼地下水道有怪聲....那請你去巡邏地下水道好了。");
		me->set_temp("police_area",1);break;
	case 2:
		command("say 嗯∼我看看∼第二碼頭有可疑份子出入...就請你去看看好了。");
		me->set_temp("police_area",2);break;
	default:
		command("say 嗯∼我看看∼第二碼頭有可疑份子出入...就請你去看看好了。");
		me->set_temp("police_area",2);break;
	}
	command("say 可能會有點危險，不過對你們這些冒險者來說，應該算不了什麼吧！");
	command("say 工作完畢後別忘了來向我領取工資。(say 工資)");
	me->set_temp("police",1);
	return 1;
}
int do_say(string arg)
{
	object me = this_player();
	int money = me->query_temp("police")*10+me->query("level")*50+me->query("popularity")*100;
	if( arg != "工資" ) return 0;
	if( !me->query_temp("police")) return 0;
	if( me->query_temp("police") < 50 ) {say("你工作的時數還不夠喔！請再努力！\n");return 1;} 
	command("say 喔！工作完成了呀！這是你的工資。");
	me->receive_money(money);
	me->add("exp", 1500+random(500));
	tell_object(me,HIW"你得到"+money+"元！你的經驗增加了!\n"NOR);
	me->delete_temp("police");
	me->delete_temp("police_area");
	return 1;
}