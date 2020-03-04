#include <ansi.h>
#include <path.h>
inherit NPC;
void create()
{
        set_name("步六弧", ({ "bu liu hu","bu","hu" }) );
        set("title", HIR"巧手玲瓏仙"NOR);
        set("gender", "男性" );
        set("long",@long
	步六弧其實是一個匈奴人, 在靈宗大舉討伐異族後, 流浪天
	涯, 直到十七歲方開始學習匠藝, 天賦加之後天的努力, 在二十
	四歲時便與左天斗分庭抗禮, 也因此穫得了巧手玲瓏仙的稱號.
	但其特異的行事風格並不為武林人事接受, 在一次被自己的所打
	造的武具砍傷後便退隱到此, 不過他偶而還是會替武林人物打造
	用具.
	long
        );      
        set("age",56);
        set("level",30);
        set("race","human");
        set("chat_chance", 10);
        set("chat_msg", ({
             "步六弧嘆道：最近都沒啥有趣的耗工啊...。\n",
	     "步六弧嘆了一口長氣\n",
	     "步六弧自言自語道: 不知師父過的如何了 ?\n",
        }));

        set("chat_chance_combat", 50 );        
        set("chat_msg_combat", ({
                "步六弧哼的一聲, 似乎十分不屑.\n",
         }) );
  
        setup();
}

int accept_object(object who,object ob,)
{
        
        if(ob->query("id")!="coin" ) return 0;
        if (ob->query_amount() == 500)
        {
                command("nod");
                message_vision(HIY "$N將五百文錢交給步六弧.。\n" NOR ,who);
                who->receive_money(- ob->query_amount() );
                message_vision(HIY "$N小兄弟需要些什麼 ?。\n" NOR ,who);
                return 1;
        }

        return 1;
}
