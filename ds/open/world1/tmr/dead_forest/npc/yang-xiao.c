// 七彩之矢(rainbow-arrow) Quest
#include <npc.h>
#include <ansi.h>
#include <skill.h>

void create()
{
        set_name( "楊嘯" , ({ "yang xiao","xiao"}) );
        set("long",@long
　　楊嘯是一個壯碩的中年男子，長得英偉非凡，雙眼透露著俠義
之氣，有種讓人折服的英雄氣概，讓人一見就心生好感。不過他臉
色非常蒼白，呼吸急促不順暢，胸口的衣服上也沾滿了血漬，似乎
受了很嚴重的內傷。
long
);
        set_race( "strength" );
        set("age", 35 );
        set_attr( "str" , 25 );
        set_skill( "axe" , 120);
        set_skill( "dodge" , 100 );
        set_skill( "unarmed" , 100 );
        set_skill( "parry" , 100 );
        set("chat_chance", 5 );
        set("chat_msg", ({
                        "楊嘯喃喃自語道：「想不到今日要斃命於此，滿腔的雄心壯志再也沒法子實現了.....」\n",
			"楊嘯忽然劇烈地咳了起來，臉上一陣青一陣白的，似乎快要死的樣子......\n",
        }));
        setup();
        set_level( 20 );
        carry_object(__DIR__"obj/wu-cloth")->wear();
        carry_object(__DIR__"obj/steel-boots")->wear();
}

void relay_say(object ob, string arg)
{
  	   object letter;
  	   // 已學得七彩之矢的人，則不必再解了
  	    if( ob->query_learn("rainbow arrow") ) return;
		if( ob->query_temp("quest-yang-xiao") == 2 ) return ;
        if( arg=="雄心壯志")  {
        	do_chat(
        		({
        			"楊嘯聽到這四個字之後，隨即呆了好一會兒....\n",
        			"楊嘯搖了搖頭說道：「唉...此時再提這也沒用了，如今我心裡牽掛的反而是另一件事啊...」\n",
	            })
            );
            return ;
        }
        if( arg=="另一件事")  {
        	do_chat( ({
        			"楊嘯嘆了口氣，說道：「我自十歲離開家之後，就再也沒有回家看我母親了...」\n",
        			"楊嘯呆望著門外，繼續說道：「如今已經二十個年頭了，我想我已經傷重難癒，無法回家了...」\n",
        			"楊嘯頓了一下，似乎做了什麼決定，問道：「不知是否能麻煩你幫個忙？」\n",
	            }) );
            ob->set_temp("quest-yang-xiao" , 1);
            return ;
        }
        if( ob->query_temp("quest-yang-xiao") == 1 ) {
    		if( arg=="好") {
		       	do_chat( ({
"楊嘯喜道：「那就麻煩你幫我將這書信送交給我老母，好讓她還知道我這個不孝子很是想念她...」\n",
        				"楊嘯「哇」地一聲吐了大口鮮血，真不知道還能活多久...\n",
	        	    })     );
	            letter = new(__DIR__"obj/letter" );
	            letter->move( ob );
	            ob->set_temp("quest-yang-xiao" , 2);
    		}
    		if( arg=="不好") {
		       	do_chat(({ "楊嘯淡然說道：「那也無妨，就不打擾你的時間了。」\n", })   );
	            ob->delete_temp("quest-yang-xiao");
    		}    	
		}
       if( ob->query_temp("quest-yang-xiao") == 3 && arg=="已經原諒你了" ) {
	            if( ob->query("skills_point") + 3 >  SKILL_MAX_POINT )  {
					// 技能點數不足
					do_chat( ({
						(: command(":D") :) ,
"楊嘯顯然非常高興的說道：「真是謝謝你的幫忙了，我如今已是將死之身，實不知有何可以回報...」\n" ,
						 "楊嘯道：「楊某會記得你的大恩大德，只盼來世再報了...」\n" 
					}) );
					ob->delete_temp("quest-yang-xiao");
				} else {
					do_chat( ({
						(: command(":D") :) ,
						"楊嘯顯見非常高興的說道：「真是謝謝你的幫忙了，我如今已是將死之身，實不知有何可以回報...」\n" ,
			  		 	"楊嘯道：「楊某會記得你的大恩大德，只盼來世再報了...」\n" 
						"楊嘯頓了一頓道：「我這兒有套家傳的絕學，不知你是否有興趣想學？」\n" 
					}) );
					ob->set_temp("quest-yang-xiao" , 4);
				}
			return;
		}
       if( ob->query_temp("quest-yang-xiao") == 4 ) {
			if( arg=="想") {
				tell_object( ob , CYN "楊嘯附在你耳邊，將口訣快速地唸過一遍....\n" NOR );
   	            if(ob->query("skills_point") + 3 >  SKILL_MAX_POINT )  {
					tell_object( ob , CYN "(但是你完全聽不懂他所講的內容...)\n" NOR );
				}
				else {
					tell_object( ob , CYN "\n(你似乎對於「七彩之矢」這個技能有個初步的認識了...)\n" NOR );
					tell_object( ob , HIY "\n(你的技能點數減少三點了。)\n" NOR );
                    ob->improve_skill( "rainbow arrow" , ob->query_attr("int") );
				    ob->add("skills_point" , 3 );
				}
				ob->delete_temp( "quest-yang-xiao" );
				return;
			}
			if( arg=="不想") {
				do_chat( ({ "楊嘯道：「那好，你的大恩大德，楊某只有來世再報了...」\n" }) );
				ob->delete_temp( "quest-yang-xiao" );
				return;
			}
		}
}

