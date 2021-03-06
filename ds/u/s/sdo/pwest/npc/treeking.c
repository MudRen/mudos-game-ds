#include <ansi2.h>
inherit NPC;

void create()
{
	set_name(HIG"迷霧森林之王"NOR, ({ "king of forg forest","king"}) );
        set("long", @LONG
在你面前的是一個全身纏滿樹藤的中年男子，樹藤之下可以看到結實
的肌肉。他面帶著慈祥的神情。
LONG
	);
        set("level",50);
        set("age",500);
	set("race","monster");
	set("gender","中性");
        set("combat_exp", 20000);

        set("talk_reply","你造訪迷霧森林有什麼事情？\n");
    	set("inquiry/迷霧森林", 
    	"迷霧森林是根據遠古的契約所產生的，是為了將妖精國度\n"
    	"隱藏起來，不受外界的侵擾。\n");
    	set("inquiry/妖精國度",
    	"那是由精靈所構成的國家，因為精靈個性高傲，不喜歡和\n"
    	"其他種族打交道，所以將自己的國家隱藏起來。\n");
        setup();
}
int accept_object(object me,object ob)
{
        object obj,book;
        obj=this_object();
        me=this_player();
        book=present("adventure notebook",me);
        if(ob->name()!="妖精之淚\")
        	return notify_fail("謝謝你，但是我不需要這個。\n");
        if(obj->is_busy() )
        	return notify_fail("我現在沒空！！\n");
        message_vision("$N給了$n一顆"+ob->query("name")+"。\n",me,obj);
        obj->start_busy(2);
        destruct(ob);
        command("smile");
        if(book->query("quests/fogforest")==1 || book->query("quests/fogforest")==2) 
        	return notify_fail("");
        if(objectp(book=present("adventure notebook",me)) && me->query_temp("sdpquest/step1")==3 && me->query_temp("sdpquest/step2")==3 && me->query_temp("sdpquest/step3")==1)
        {
        	message_vision(
        	"$n看著$N不停的嘖嘖稱奇。\n\n"
        	"$n對著$N說：沒想到現在還有人能獲得妖精的信任。\n"
        	"好吧，那麼就讓我給你一些幫助吧。\n"
        	"我可以按照你的希望在你的四項屬性中的其中一項增\n"
        	"加一點，你決定好在用(plus 屬性)來增加吧。\n"
        	"你決定好了之後，我會直接將你送到出口。就這樣，\n"
        	"人類冒險者\n",me,obj);
        	add_action("do_plus","plus");
        	
        }
        return 1;
}
int do_plus(string arg)
{
	object book;
	
	if(!arg) return notify_fail("請用[plus 屬性(str等)]");
	if(arg=="str") { 
		this_player()->add("addition/str",1);
		tell_object("你的力量提升了！\n");}
	if(arg=="con") {
		this_player()->add("addition/con",1);
		tell_object("你的體質提升了！\n");}
	if(arg=="int") { 
		this_player()->add("addition/int",1);
		tell_object("你的智慧提升了！\n");}
	if(arg=="dex") {
		this_player()->add("addition/dex",1);
		tell_object("你的敏捷提升了！\n");}
	else{return notify_fail("我不能提升這種屬性。\n");}
	
	if(book=this_player()->query_temp("notebook"))
	{
		book->add_quests_note("fogforest",
        	"想不到能獲得樹王的幫助...\n");
        	this_player()->set_temp("sdoquest/step3",2);
        	this_player()->set_temp("sdoquest/step4",1);
        
        	book->set_quests("fogforest",2);
        	this_player()->save();
        
        	message_vision(
		HIW"只見$n"HIW"高舉雙手，招來一陣白霧，將$N"HIW"包圍住，接著$N"HIW"就消失了。\n",this_player(),this_object());
        	this_player()->move(__DIR__"forestout");
        }
        return 1;
}