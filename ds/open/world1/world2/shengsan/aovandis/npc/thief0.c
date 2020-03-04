#include <ansi.h>
inherit NPC;
void create()
{
//=========================基本設定==========================

        set_name( "陳駾", ({ "chen tuay","chen","tuay"}));
        set("long", "一個偷偷摸摸的扒手﹐正躲在這裡伺機偷東西。\n"
        );
        set("level",7);
        set("gender", "男性");
        set("race", "人類");
        set("age", 16);

        set("str",7);			//設定屬性(可免)
        set("dex",24);			//也可以只設定 level
        set("con",13);			//其他沒設定的屬性系統就會自動產生,

        set("evil",15);			//邪惡度 20 (正的表邪惡, 負表善良)

   set("attitude", "peaceful");   //溫和的 NPC。


  set("chat_chance", 1 );  //動作機率
  set("chat_msg", ({       //動作內容
"你覺得這裡似乎有人在偷窺你..\n",
"",
"",
}) );

//===========================問題回答==================================
set("inquiry/name", @LONG
  你..你怎麼看的到我????
LONG );

//set("talk_reply","你少管閒事....");
//=========================戰鬥訊息===========================
     set("chat_chance_combat", 10);
     set("chat_msg_combat", ({
 "陳駾用台語大罵 : 「幹凝娘∼﹗好膽賣造﹗」\n",
     }) );
	
	set_temp("hide",1);
        setup();

//==========================裝備道具=============================
      add_money("dollar", 110);		//帶的錢
      carry_object(__DIR__"obj/ironkey");
      carry_object(__DIR__"wp/fork0")->wield();
      carry_object(__DIR__"eq/cloth2")->wear();
}
