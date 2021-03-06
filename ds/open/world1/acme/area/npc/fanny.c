#include <ansi.h>
inherit NPC;
void say_delay1(object me);
void say_delay2(object me);
void nod_delay(object me);
void create()
{
        set_name("爛醉的劍客", ({ "swordsman","man" }) );
        set("nickname", "我欲長醉不復醒");
        set("gender", "男性" );
        set("long",
            "一個混身酒氣的落魄中年男子，但從他眼裡仍可看出一絲絲的豪氣。\n"
            "卻不知他是在憂愁何事，只見他黃湯一杯一杯下肚，好似不會醉一樣。\n"
           );
        set("age",45);
        set("level",30);
        set_skill("dodge", 80);
        set_skill("parry", 70);
        set_skill("sword", 85);
        set_skill("hungchen-sword", 100);
       set("chat_chance", 5);
        set("chat_msg", ({
                "爛醉的劍客吟道：紅塵迢迢，痴情緲緲，只應目空一切好；...........\n",
                "爛醉的劍客吟道：此生未了，心無所擾，願換它半世逍遙；...........\n",
                "爛醉的劍客吟道：醒時言笑，夢中飄搖，歎天黑怎生得早？...........\n",
                "爛醉的劍客吟道：來生難料，愛恨勾銷，對酒當歌恁任年華老！...........\n",
        }));
        set("inquiry", ([
            "情": "唉！！問世間情為何物？\n",
        ]) );
        setup();
	carry_object(__DIR__"wp/hung");
}
void init()
{
        object me,obj;
        me=this_player();
        obj=this_object();
        add_action("do_say","say");
        add_action("do_nod","nod");
        if(objectp(obj=present("wine",me) ) && me->query_temp("quest/wine") == 0 )
        {
          call_out("wine",2,obj);
        }
        if(me->query_temp("quest/wine") == 8)
        {
          call_out("wine2",2,obj);
        }
}
void wine()
{
    object me;
    me=this_player();
    message_vision("爛醉的劍客看來好像被$N身上的某樣東西吸引著了，一直注視著$N。\n",me);
    say("爛醉的劍客說：這位"+RANK_D->query_respect(me)+"，有酒嗎？\n");
    command("lick");
}
int accept_object(object who, object ob)
{
           object me,book;
           me=this_player();
        if( ob->query("water_remaining") == 0 ) return notify_fail("爛醉的劍客說道：酒！酒！酒！我只要酒！\n");
           if( ob->name() != "燒刀子" )
           {
		message_vision("$N給了爛醉的劍客一個"+ob->query("name")+"。\n",me);
		say("爛醉的劍客一飲而盡，說道：這個不是"+ob->query("name")+"嘛，這酒不夠濃烈吧，喝不醉人的...\n");
             	command("sigh");
             	destruct(ob);
             	return 1;
           } 
           else {
             if(me->query_temp("quest/wine") == 0)
             {
message_vision("$N給了爛醉的劍客一個"+ob->query("name")+"。\n",me);
              say("眼睛射出異樣的光芒，開始細細的品嘗。\n");
              say("爛醉的劍客一邊喝著燒刀子，一邊不停的大嘆：好酒！好酒！\n");
               me->set_temp("quest/wine",1);
               destruct(ob);
               return 1;
             }
             else {
               message_vision("爛醉的劍客看來似乎被$N灌醉了，嘴裡開始反覆的念著一些你聽\n",me);
               say("不清楚的字句，糢糢糊糊之中只聽到一直重覆著「小娟」這個名字。\n");
               if(book=me->query_temp("notebook"))
          	 book->add_quests_note("SadSworder","劍客醉時提起了小娟這個人..或許\我應該問問小娟的消息[say 小娟?]。");
               me->set_temp("quest/wine",2);
               destruct(ob);
               return 1;
             }
           }
}
int do_say(string arg)
{
      object me,obj;
    me=this_player();
    obj=this_object();
    if( !me->query_temp("quest/wine") >1 ) return 0;
    if(!arg) return 0;
    else {
         if(strsrch(arg,"小娟")!=-1 && me->query_temp("quest/wine") == 2 && !busy)
         {
           	busy=1;
		call_out("say_delay1",0,me);
		return 0;
         }
         else {
           if(strsrch(arg,"笑紅塵")!=-1 && me->query_temp("quest/wine") ==4 && !busy)
           {
           	busy=1;
		call_out("say_delay2",0,me);
		return 0;
           }
        }
    }
}

void say_delay1(object me)
{
	object book;
	busy = 0;
	if(!me) return;
	if(environment(me) != environment(this_object()) ) return;
	say("爛醉的劍客喉間發出「咕」的一聲，兩眼直瞪著你看。\n");
        command("say 咦！？"+RANK_D->query_respect(me)+"你認識她！？");
        if(book=me->query_temp("notebook"))
        book->add_quests_note("SadSworder","劍客問起小娟的事..或許\我應該點頭以便探聽小娟的消息。");
        me->set_temp("quest/wine",3);
        return;
}
void say_delay2(object me)
{
       object book,shawl;
	busy = 0;
	if(!me) return;
	if(environment(me) != environment(this_object()) ) return;
              command("sorry");
              this_object()->set("name","笑紅塵");
              command("say 在下並非純心相瞞，實在是....");
              say("笑紅塵歎了口氣說道：有酒無情，有情無酒，情酒俱在，人生一快。\n");
              say("笑紅塵續道："+RANK_D->query_respect(me)+"，日後你就會明白的...\n");
              shawl=new(__DIR__"obj/shawl");
              shawl->move(me);
              message_vision("笑紅塵給$N一個絹布。\n",me);
              if(book=me->query_temp("notebook"))
              	book->add_quests_note("SadSworder","笑紅塵的絹布.. 或許\應該拿給小娟看看。");
              me->set_temp("quest/wine",5);
        return;
}
int do_nod(string arg)
{
        object me;
      me=this_player();
      if(me->query_temp("quest/wine") ==3 )
      {
           	busy=1;
		call_out("nod_delay",0,me);
		return 0;
      }
}
void nod_delay(object me)
{	
	object book;
	busy = 0;
       	if(!me) return;
	if(environment(me) != environment(this_object()) ) return;
       say("爛醉的劍客看來一副驚慌失措的樣子，他緩緩的低下頭沉吟了一會。\n");
       say("爛醉的劍客拿起了手中的紅塵劍，看了看，眼中不禁流露出溫柔的神情。\n");
       tell_object(me,"(你看到這一把劍，讓你想起了剛剛的假設，他究竟是不是笑紅塵呢？)\n");
       if(book=this_player()->query_temp("notebook"))
           book->add_quests_note("SadSworder","紅塵劍居然在劍客手中..難道他就是笑紅塵? [想問他就打: say 你是笑紅塵?]。");
       me->set_temp("quest/wine",4);
       return;
}
void wine2()
{
      int i,exp,j;
      string *msg;
      object me,obj,book;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("suicide");
      switch( i ) {
          case 0:
            message_vision("( $N一碰到笑紅塵，就把事情的經過一五一十的告訴他了。 )\n",me);
            say("笑紅塵淡淡的說：想不到她至今仍連個機會都不給我...\n");
            obj->set_temp("suicide",i+1);
            call_out("wine2",5,obj);
            break;
          case 1:
            say("笑紅塵拔劍出鞘，舉起劍隨手一揚，一劍刺穿了你身後的牆壁...\n");
            command("say 這位"+RANK_D->query_respect(me)+", 這劍招就傳了你吧...\n");
            obj->set_temp("suicide",i+1);
            call_out("wine2",5,obj);
            break;
          case 2:
            say("笑紅塵身形四處飄忽不定，一剎那間把【紅塵劍法】演了一遍。\n");
            message_vision(" ( $N牢牢的記下所有的劍招 )\n",me);
              if(me->query_skill("hungchen-sword") == 0)
               {
                me->set_skill("hungchen-sword",11);
                     }
            obj->set_temp("suicide",i+1);
            call_out("wine2",5,obj);
            break;
          case 3:
            say("笑紅塵嘆道：沒有人可以真正看破紅塵，唯有....\n");
            command("sigh");
            obj->set_temp("suicide",i+1);
            call_out("wine2",5,obj);
            break;
          case 4:
            say("笑紅塵喃喃吟道：紅塵迢迢，痴情緲緲，只應目空一切好；...........\n");
            obj->set_temp("suicide",i+1);
            call_out("wine2",2,obj);
            break;
          case 5:
            say("笑紅塵喃喃吟道：此生未了，心無所擾，願換它半世逍遙；...........\n");
            obj->set_temp("suicide",i+1);
            call_out("wine2",2,obj);
            break;
          case 6:
            say("笑紅塵喃喃吟道：醒時言笑，夢中飄搖，歎天黑怎生得早？...........\n");
            obj->set_temp("suicide",i+1);
            call_out("wine2",2,obj);
            break;
          case 7:
            say("笑紅塵喃喃吟道：來生難料，愛恨勾銷，對酒當歌恁任年華老！...........\n");
            obj->set_temp("suicide",i+1);
            call_out("wine2",5,obj);
            break;
          case 8:
            say("笑紅塵提起手中的劍，往自已的脖子一刎，嘴裡帶著一絲淒苦的笑容。\n");
            say("笑紅塵自殺了！！！\n");
            obj->set_temp("suicide",i+1);
            call_out("wine2",3,obj);
            break;
          case 9:
            me->delete_temp("quest/wine");
            if(book=me->query_temp("notebook"))
            {
		book->add_quests_note("SadSworder","笑紅塵因為不堪情苦而自殺了，死前並將劍法傳授給我，任務終於告一段落。");
            	if(!book->query_step("SadSworder"))
            	{
			book->set_quests("SadSworder",1);
			msg=book->query_quest_note("SadSworder");
			j=sizeof(msg);
			write(sprintf("%s恭喜你完成了這個任務，你的完成度是: %d%%\n",HIC,(100*j/9)));
			exp= j*10000+random(10000);
			write(sprintf("%s你得到了%d點經驗值，並且聲望提昇了%d點。\n\n%s",HIW,exp,j,NOR));
			me->add("exp",exp);
			me->add("popularity",j);
			me->save();
		}
            }
            ::die();
            break;
        }
}
