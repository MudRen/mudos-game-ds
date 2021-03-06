inherit NPC;
void create()
{	
	set_name("瑟琳娜", ({ "selina"}) );
        set("long", @LONG
在你面前的是一位美麗的妖精。白皙的皮膚，和一頭亮麗的長髮，讓
你呆了一下，這種出眾的氣質果然只能在精靈的身上見到。
LONG
	);
        set("level",30);
        set("age",80);
	set("race","人類");
	set("gender","女性");
        set("combat_exp", 7000);
        
        set("title","妖精");

        set("talk_reply","你好，人類的冒險者。\n");
        setup();

}
void init()
{
	add_action("do_inquiry","inquiry");
}
int do_inquiry(string arg)
{
	object book,me,b;
	me=this_player();
	
	if(!me) return 0;
	if(me->query_temp("sdoquest/step2")!=2) return 0;
	if(arg != "通過方法" || arg != "通過的方法") return 0;        
        if(objectp(book=present("adventure notebook",me)))
        {
        	me->start_busy(10);
        	write(
        	"瑟琳娜說：迷霧森林的屏障是來自於一顆巨大的水晶，\n"
        	"而由森林中的四種神樹構成結界，只要水晶不消失，結界就會永遠存在。\n"
        	"所以相對的，可以根據神樹的種類來推測正確的出口。\n"
        	"想要通過，就要記好這一首古老的詩。\n\n"
        	"瑟琳娜輕輕的唸了起來~~~\n\n"
        	"『遙遠北之國的諸神阿，請用那潔淨的白楊木為我們清掃邪惡；』\n"
        	"『並且盼望能賜予吾人那日昇處蒼柏的智慧，為了對抗黑暗的勢力；』\n"
        	"『勇士們的鬥志宛如南灣邊的楓葉般熾熱；』\n"
        	"『祈望能在日落之時伴隨著桂花香凱旋而歸！』\n");
        	book->add_quests_note("fogforest",
        	"你牢牢的記下方法，終於要朝終點前進了。\n");
        	me->set_temp("sdoquest/step2",3);
        	if(me->query_temp("sdoquest/step2")==3 && me->query("evil") <= -200)
        	{
        		b=new_ob(__DIR__"obj/tearofelf.c");
        		b->move(this_object());
        		
        		write(
        		"瑟琳娜說：這位冒險者，請等一等...\n\n"
        		"我希望你在通過迷霧森林前，先依照這個東西的指示，\n"
        		"在森林裡找一個人，並且把這東西交給他，他會給你幫\n"
        		"助的。\n");
        		command("give tear to "+me->query("id"));
        		me->set_temp("sdoquest/step3",1);
        	}
        }
        return 1;
}