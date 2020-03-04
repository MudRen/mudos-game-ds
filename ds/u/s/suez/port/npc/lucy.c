#include <ansi.h>
inherit NPC;
int notice();
void create()
{
       set_name(HIM"露西"NOR,({"lucy"}));
       set("long",@LONG
    她是港務公所的書記員，似乎在為什麼事情苦惱？你可以問問看。說
不定能幫上什麼忙。
LONG
);
       set("gender","女性");
       set("age", 18);
       set("level", 3);

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("hmm"):),
             }));

	set("talk_reply","嗯...(看來她沒注意到你，你最好讓她注意到你。)");    
       setup(); 
       carry_object( __DIR__"eq/dress")->wear();         

}
void init()
{
        ::init();
        add_action("do_say","say");
}
void relay_emote(object ob, string verb, object me)
{	
        if( !userp(ob) ) return 0;
        switch(verb) {
        case "sex":
                command("slap "+ob->query("id") );
                command("say 喂！你太過分了！");	
                break;
        case "kiss":
                command("blush " );
		notice();	
                break;
	case "kick":
		command("say 啊？");
		notice();
                break;
	case "slap":
		command("say 啊？");
		notice();
                break;
	case "pat":
		command("say 啊？");
		notice();
                break;
	case "kok":
		command("say 啊？");
		notice();
                break;
	case "beep":
		command("say 啊？");
		notice();
                break;
        default:
                break;
        }
}
int notice()
{
	object me;
	int i;
	me=this_player();
	i=me->query_temp("light_to_future");
        if( me->query("sarsass_1") > 0 )  
	{
		command("say 咦﹖我是不是在哪裡看過你﹖\n");
		return 1;
	}
	switch(i){
	case 1:
		command("say 抱歉，我現在心情不好。請你有事快說。(say)");break;
	case 2:
		command("say 唉...你不願意幫忙嗎﹖");
		me->delete_temp("light_to_future");
		break;
	case 3:
		command("say 啊！是你！事情辦的怎麼樣了﹖沒問題吧﹖我覺得好緊張喔...");break;
	case 4:
		tell_object(me,YEL"你面有慚色的準備跟露西說明來龍去脈...\n"NOR);
		command("jump");
		command("say 剛剛我看到燈塔發出光芒，是修好了吧！太好了！");
		tell_object(me,CYN"你的內心交戰著，要說出真相﹖(say no)或著不說﹖(say yes)\n"NOR);
		me->set_temp("light_to_future",5);
		break;
	case 5:
		command("say 事情到底怎樣了﹖是成功\了嗎﹖");
		tell_object(me,CYN"你的內心交戰著，要說出真相﹖(say no)或著不說﹖(say yes)\n"NOR);
		break;

	default:
	command("say 請問您有什麼事嗎﹖");
	me->set_temp("light_to_future",1);
		break;
	}
	return 1;
}
void do_say(string arg)
{
	object me=this_player();
	if(me->query_temp("light_to_future")==1)
	{
	 if(arg == "苦惱" || arg =="事情" || arg =="幫忙" )
	{
	 tell_object(me,"露西歪著頭仔細的打量你一般。\n");
	 command("say 其實我們這裡有一個小小的問題....");
	 command("say 從這裡一直往西，有個懸崖。");
	 command("say 懸崖上有一座不知道何時何人建造的燈塔。");
	 command("say 之前這裡只是個漁村，不太需要燈塔，所以也沒人去理會。");
	 command("say 但是最近有許\多來往東方大陸的商船...燈塔就變成必須的...");
	 command("say 雖然之前我們也有派人上去，想要啟動這個燈塔。");
	 command("say 但是燈塔的結構沒有人見過...所以至今仍無法啟動。");
	 command("say 現在商會出1000元，給有辦法啟動燈塔的人。");
	 command("say 看你好像挺有本事的樣子，你願意試試看嗎﹖願意的話請輸入(nod lucy)");
	 me->set_temp("light_to_future",2);
	 add_action("do_nod","nod");
	}
	 return ;
	}
	if(me->query_temp("light_to_future")==5)
	{
	 switch(arg){
	 case "yes":
		tell_object(me,HIG"你想了想...算了...將錯就錯吧！\n"NOR);
		command("say 這些是你的酬勞！謝謝你！");
		me->receive_money(1000);
		me->add("exp", 1500+random(500));
		tell_object(me,HIW"你得到1000元！你的經驗增加了!\n"NOR);
		me->delete_temp("light_to_future");
		me->set("sarsass_1",1);
		break;
	 case "no":
		tell_object(me,HIY"雖然不忍心掃她的興，但是誠實的你決定還是要說出真相！\n"NOR);
		command("say 是嗎﹖又是這個樣子.....");
		command("say 不過還是謝謝你，雖然沒有酬勞，但是我會記得你的好心的。");
		me->add("exp", 2000+random(500));
                me->add("popularity",1);
		tell_object(me,HIW"你的經驗增加了！你的聲望增加了!\n"NOR);
		me->delete_temp("light_to_future");
		me->set("sarsass_1",1);
		break;
	 default: break;
	 }
	return;
	}
}
void do_nod(string arg)
{
	object me=this_player();
	if(me->query_temp("light_to_future")==2)
	{
	if(arg == "lucy"){
	command("say 是嗎﹖太好了！那就拜託你了！");
	command("smile");
	me->set_temp("light_to_future",3);
	}
	return;
	}
return;
}
