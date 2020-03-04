inherit NPC;
void create()
{
	set_name("雷恩太太", ({ "leion"}) );
        set("long", @LONG
一個中年婦人，滿臉焦慮神色的她似乎心中有很嚴重的問題。
LONG
	);
        set("level",15);
        set("age",40+random(5));
	set("race","人類");
	set("gender","女性");
        set("combat_exp", 1000);
        
        set("title","村民");

        set("talk_reply","你有看到我的兒子嗎？\n");
        set("inquiry/兒子", 
        "我的兒子叫做奈斯，他是一個非常優秀的獵人。可是他好幾天沒回來了。\n");
        setup();
        
}
int accept_object(object me,object ob)
{
        object obj,book,l;
        obj=this_object();
        me=this_player();
        
        if(ob->name()!="奈斯的頭巾")
        	return notify_fail("謝謝你，但是我不需要這個。\n");
        if(obj->is_busy() )
        	return notify_fail("我現在沒空！！\n");
        message_vision("$N給了$n一條"+ob->query("name")+"。\n",me,obj);
        obj->start_busy(7);
        destruct(ob);
        message_vision(
        "$N告訴了$n取得的經過，$n不停的哭哭啼啼，好不容易\n"
        "止住眼淚\，才萬分的感謝$N，並且說道：我幫你寫一封信給村長，他\n"
        "會幫你的！\n",me,obj);
        
	l=new_ob(__DIR__"obj/letter.c");
	l->move(this_object());
	
        command("give letter to "+me->query("id"));
        if(objectp(book=present("adventure notebook",me)) && me->query_temp("sdoquest/step1")==3)
        {
        	book->add_quests_note("fogforest",
        	"有了這個，村長應該會告訴我了吧。\n");
               	me->set_temp("sdoquest/step2",1);
        }
        return 1;
}