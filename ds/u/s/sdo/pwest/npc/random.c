inherit NPC;
string do_book();

void create()
{
	set_name("瑞敦", ({ "random"}) );
        set("long", @LONG
一個平凡的村民，由手腳上的繭可以看得出來他大概長年在田地裡工
作。
LONG
	);
        set("level",15);
        set("age",50);
	set("race","人類");
	set("gender","男性");
        set("combat_exp", 1000);
        
        set("title","村民");

        set("talk_reply","真是困擾...\n");
        set("inquiry",([
        "商隊":	"就是運送貨物到這裡的車隊，裡面有村子裡的人託人購買的物品。\n"
        	"像我就買了作物的種子，結果現在種子沒了，我還不知道要拿什麼\n"
        	"東西播種。真是傷腦筋...\n",
        "困擾":this_object()->do_book(),
        ])); 

        setup();
}
string do_book()
{
	object book,me;
	me=this_player();
	if(!me) return 0;	
	if(objectp(book=present("adventure notebook",me)) && me->query_temp("sdoquest/step1")==2)
	{
		book->add_quests_note("fogforest",
        	"看來這個問題很嚴重，我是不是該去看看情況，順便尋找奈斯的下落...。\n");
               	me->set_temp("sdoquest/step1",3);
		
		return "就是那一群怪物阿！不知道從哪裡來的，一開始還只是趁大家\n不注意時稻田裡搶奪作物，結果現在竟然還攻擊商隊！所以上\n次村子開會時，奈斯主動表示要去消滅牠們，不知道怎樣了，\n";
	}
}	
int accept_object(object me,object ob)
{
        object obj;
        obj=this_object();
        me=this_player();
        
        if(ob->name()!="植物種子")
        	return notify_fail("謝謝你，但是我不需要這個。\n");
        if(obj->is_busy() )
        	return notify_fail("我現在沒空！！\n");
        message_vision("$N給了$n一些"+ob->query("name")+"。\n",me,obj);
        obj->start_busy(7);
        destruct(ob);
        command("dance");
        command("thank "+me->query("id"));
        this_player()->add("exp",1000);
        tell_object(
        "你得到 1000點經驗值！\n");
        message_vision(
        "$n說：今年不怕沒種子播種啦！\n",me,obj);
        return 1;
}