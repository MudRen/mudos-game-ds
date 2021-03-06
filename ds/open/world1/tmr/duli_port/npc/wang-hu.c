#include <npc.h>
#include <ansi.h>
#include <skill.h>
inherit F_VILLAGER;
void create()
{
        set_name("王虎", ({ "wang hu","hu" }) );
        set("long",@long
在你眼前的是一位渾身肌肉結實的男人，身上穿著一件繡有「銀刀」
字樣的武鬥服，看他身上帶著行李，站在這路口四處張望，似乎在找尋什
麼一樣。
long
);
        set_race("human");
        set("age", 24);
        set_stat_maximum("gin", 150);
        set_stat_maximum("hp", 200);
        set_skill("blade",60);
        set_skill("dodge",100);
        set_skill("silver-blade steps",80);     
        map_skill("dodge","silver-blade steps");


        set_attr("str",25);
        set("chat_chance", 5);
        set("chat_msg", ({
                "王虎拉住了一個路過的人，詢問了他一些事情後，又搖搖頭走了回來。\n",
                "王虎喃喃自語道：「第一試驗場到底在那兒呢？？真是難找....」。\n",
        }));

        set("title","銀刀門門徒");
        setup();
		set_level(10);
        carry_object(__DIR__"obj/silver-blade")->wield();
          carry_object(__DIR__"obj/fighter-cloth")->wear();

}

int accept_fight(object ob)
{
        do_chat("王虎得意笑了笑，說道：「就讓你試試我這個準獵人的厲害吧！！」 \n");
        return 1;
}
void init()
{
        object me=this_player();
        if( me->query_learn("silver-blade steps") )
		command("bow "+me->query("id"));
}


/* Quest:可學到 銀刀門身法 輕功 */
void relay_say(object ob, string arg)
{
        if( ob->query_learn("silver-blade steps")  )      return;
        if( strsrch(arg,"第一試驗場")!=-1 ) {
                 do_chat("王虎苦惱道：「是呀，我要去參加今年的獵人試驗，但是一直找不到。」 \n");
                ob->set_temp("duli_port/wang-hu",1);
                return;
        }
        if( strsrch(arg,"往北邊山上的一棵大杉木走去")!=-1
         && ob->query_temp("duli_port/wang-hu")==1 )
        {
                message_vision(CYN"王虎向北邊的方向望了望，忽然像知道了什麼一樣，喜道：「真是謝謝你幫我這個大忙。」 \n"NOR,ob);
                message_vision(CYN"王虎喃喃自語道：「我應該怎麼答謝你呢？？」 \n"NOR,ob);
				/* 學習技能點數不夠	*/
                                  if(ob->query("skills_point")+1 >  SKILL_MAX_POINT ) {
			        message_vision(CYN"王虎揮了揮手，往北邊的道路走了過去。\n" NOR,ob);
		            ob->delete_temp("duli_port/wang-hu");
	                destruct(this_object());
				}
                message_vision(CYN"王虎對著你問道：「不知你是否想要本門的一套輕功呢？？」\n" NOR,ob);
                ob->set_temp("duli_port/wang-hu",2);
                return;
        }
        if( strsrch(arg,"不想")!=-1  && ob->query_temp("duli_port/wang-hu")==2 )
        {
                message_vision(CYN"王虎嘆道：「那好吧，那我就先一步了。」\n"NOR,ob);
                message_vision(CYN"王虎揮了揮手，往北邊的道路走了過去。\n" NOR,ob);
                ob->delete_temp("duli_port/wang-hu");
                destruct(this_object());
                return;
        }

        if( strsrch(arg,"想")!=-1  && ob->query_temp("duli_port/wang-hu")==2 )
        {
                message_vision(CYN"王虎喜道：「那好，我這個人最講究有恩必報的。」\n"NOR,ob);
                message_vision(CYN"王虎在$N耳邊細細講了幾句話，似乎在傳授什麼口訣。\n" NOR,ob);
                message_vision(CYN"王虎揮了揮手，往北邊的道路走了過去。\n" NOR,ob);
                ob->delete_temp("duli_port/wang-hu");
                ob->improve_skill("silver-blade steps",100);
                                /* 已學習技能點數一點   */
                                ob->add("skills_point",1);
                                tell_object(ob,HIG"(你的技能學習點數花掉一點。)\n" NOR);
                destruct(this_object());
                return;

        }

}
