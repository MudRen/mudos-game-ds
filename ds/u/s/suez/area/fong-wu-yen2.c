//蘇子奇第一位mob....超暴笑的風無影..
#include <ansi.h>
void goto_1();
void goto_2();
void goto_3();
inherit NPC;
void create()
{
        set_name( "風無影", ({ "fong-wu-yen","風無影","fong",}));
        set("long", "在你面前的是一個全身黑衣的人，雖然長的一表人才，\n"
                    "但是手上卻不知道拿了一包什麼東西。他兩隻眼睛不停\n"
                    "滴溜滴溜的轉....臉上似笑非笑的看著你，不知道正對你\n"
                    "打著什麼主意....你不禁流下斗大的一滴汗。\n");
  
        set("title",CYN "妙手空空兒"NOR);
        set("gender", "男性");
        set("age", 27);
        set("level", 55);
        set("dex", 97);
      set("adv_class",2);    
      set("class1","摘星門"); 
     set("class2","奇門");
      create_family( MAG "奇門" NOR ,2,"風");

   set("guild_gifts",({-2,-2,7,17}));
   
        set("chat_chance",3);
        set("chat_msg",({(:command, "grin":),
                                  (:command, "sing":),
                                  (:command, "snicker":),
                           (: random_move :),
  }));

        set_skill("stealing", 100);
        set_skill("sneak", 100);        
        set_skill("backstab", 100);
        set_skill("peep", 100);
        set_skill("hide", 100);
         set_skill("perception", 100);
        set("env/wimpy", 80);
        
        set("inquiry/name", "我叫做風無影，又稱妙手空空兒。
        ");

        set("talk_reply","你在這裡幫我把風吧！我進去看看有啥值錢的玩意兒。 :P");

/*set("schedule",
([
        "21" : (: goto_1 :),
        "01" : (: goto_2 :),
        "03" : (: goto_3 :),
        "07" : (: del:),
]));
*/

        setup();
        add_money("coin", 10000);
        carry_object(__DIR__"wp/cloud_dagger.c")->wield();
        carry_object(__DIR__"eq/sky-walk_b.c")->wear();
        carry_object(__DIR__"eq/stars_c.c")->wear();
}



int accept_object(object ob,object wp)
{
        object sign;
        wp=this_object()->query_temp("weapon");        
        if(ob->name()!="古老的石雕")
                return 0;
        else {

        if(wp->name()!="千雲匕")
        {
        command("say 真是多謝了...可是我沒什麼好東西可以報答你。\n");
        command("say 這樣好了，你拿這東西去一間叫月嵐客棧的地方。\n");
        command("think");
        command("say 就拿給那裡的老闆娘，她應該會給你好處的。\n");
        say("風無影好像還想說些什麼，但是搖了搖頭就放棄了。\n");
        command("idle");
        }
          else {

           say("風無影看到這個石雕頓時大喜若狂！！\n");
           command("say 太好了！謝謝你幫我找到本門之寶！\n");
           command("unwield dagger"); 
           command("grin");
           command("say 這傢伙東西是我從大內拿出來的，還不錯用。\n");
           command("say 為了報答你的恩情，這傢伙就送給你吧！\n");
           command("give dagger to " + this_player()->query("id") );
           command("say 後會有期！我去也！"); 
           destruct(ob);
           destruct(this_object());
           return 1;
        }
         return 1;
        }
         } 
void relay_emote(object ob, string verb)
 {
 	 if( !userp(ob) )
 	  return 0;

	switch(verb) {
	case "?":
			command("say 你覺得我很奇怪嗎？");
                        command("hehe");
                        command("say 你在這裡待久了很快就變得很我一樣 :P");
                        command("cac");
                        say(CYN"風無影突然消失了，只剩下他的狂笑還在你耳邊徘徊。/n"NOR);
                        destruct(this_object());
			break;
	case "pig":
			command("say 你覺得我很笨嗎？");
                        command("hehe");
                        command("say 你在這裡待久了很快就變得很我一樣 :P");
                        command("cac");
                        say(CYN"風無影突然消失了，只剩下他的狂笑還在你耳邊徘徊。\n"NOR);
                        destruct(this_object());
			break;
        case "crazy":
			command("say 你覺得我瘋了嗎？");
                        command("hehe");
                        command("say 你在這裡待久了很快就變得很我一樣 :P");
                        command("cac");
                        say(CYN"風無影突然消失了，只剩下他的狂笑還在你耳邊徘徊。\n"NOR);
                        destruct(this_object());
			break;
        case "starcraft":
                        
                        command("say 不要！你又玩不過我，一點意思也沒有。");
                        command("snort");
                        break;
        case "accuse1":
                        
                        command("say 那又如何，至少我這個蘿蔔特不會被關綠島。");
                        command("grin");
                        break;
	default:
			command(verb + " " + ob->query("id"));
                        break;
	}
}
void goto_1()
{
        if(!find_object("/open/world1/cominging/area/bnorth3")) return;
 this_object()->move("/open/world1/cominging/area/bnorth3");
 message_vision(HIG"你聽到一陣窸窸窣窣的聲音，只見$N"HIG"從牆的另一頭翻了出來。\n"NOR, this_object());
}

void goto_2()
{
        if(!find_object("/open/world1/acme/area/wynd")) return;
 this_object()->move("/open/world1/acme/area/wynd");
 message_vision(HIG"你聽到一陣窸窸窣窣的聲音，只見$N"HIG"從牆的另一頭翻了出來。\n"NOR, this_object());
}

void goto_3()
{
        if(!find_object("/open/world1/tmr/area/wynd")) return;
 this_object()->move("/open/world1/tmr/area/wynd");
 message_vision(HIG"你聽到一陣窸窸窣窣的聲音，只見$N"HIG"從牆的另一頭翻了出來。\n"NOR, this_object());
}
void del()
{
          command("say 嗯，差不多該收工了 :P");  
          say (HIB"風無影輕輕一躍，離開了你的視線。\n"NOR); 
          destruct(this_object());
        return;
}
void attack()    
{
        int hp,max_hp ;
        hp=this_object()->query("hp");
        max_hp=this_object()->query("max_hp");
        if(hp==max_hp) return 0;

          command("say 失風失風，扯呼扯呼。出師不利，逃之夭夭！！");  
          say (HIB"只見風無影朝你衝來，你還搞不清楚怎麼回事，他的身影已消失在黑暗的角落了。\n"NOR); 
          destruct(this_object());
          return ;
}
