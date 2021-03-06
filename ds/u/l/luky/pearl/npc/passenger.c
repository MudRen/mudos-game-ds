#include <ansi.h>
inherit NPC;
void create()
{
//=========================基本設定==========================

        set_name( "旅客", ({ "passenger","旅客","passenger",}));
        set("level",30);
        set("title","[1;33m外地人[m");
        set("gender", "男性");
        set("race", "人類");
        set("age", 42);
        set("evil",40);
        set("coin", 1400+random(300));
        set("long", @LONG
一個滿臉橫肉的旅客﹐正在被安全警衛盤問著。
LONG
        );

//========================態度類別=================================
   set("attitude", "heroism");    //英雄主義的 NPC。

//=============================自動動作=================================
  set("chat_chance", 3 );  //動作機率
  set("chat_msg", ({       //動作內容
"旅客用力的踢了牆壁一腳!! 似乎非常生氣..\n",
(:command("say 哇靠!! 這是什麼服務態度嘛!!!"):),
(:command("say 到底要我說幾次啊~~ 這把開山刀是我剛剛撿到的.."):),
(:command("sigh"):),
(:command("angry"):),
}) );

//===========================問題回答==================================
set("inquiry/name", @LONG
  [1;36m我叫做牛過...你問這個幹什麼?? 無聊!![m
LONG );


//=========================戰鬥訊息===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("chair "+this_player()->query("id")):),
 HIR"旅客破口大罵 : 「可惡的傢伙∼﹗我打死你﹗」\n"NOR,
     }) );

        setup();

//==========================裝備道具=============================
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"wp/kaisan_b")->wield();
      carry_object(__DIR__"eq/blackjacket")->wear();
}

void init()
{
add_action("do_kill","kill");
}

int do_kill(string arg)
{
 if(arg=="passenger")
 {
 message_vision("[1;37m安全警衛馬上站出來對$N[1;37m說: 請不要動手, 交給我們處理就好了。[m\n",this_player());
 return 1;
 }
return 0;
}

//======================動作反應======================================
void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                command("angry "+ob->query("id") );
		if(random(10)>7 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")悲慘的淒涼吶喊: 救命阿!! 救命阿!!!\n"
        	+"旅客(passenger)想謀殺我!! 旅客(passenger)是殺人兇手!![m\n");
                command("say 他@#$的, 老子正在氣頭上居然敢踢我!!");
                kill_ob(ob);
                }
                break;
        case "club":
                command("angry "+ob->query("id") );
                if(random(10)>6 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")悲慘的淒涼吶喊: 救命阿!! 救命阿!!!\n"
        	+"旅客(passenger)想謀殺我!! 旅客(passenger)是殺人兇手!![m\n");
                command("say 他@#$的, 老子正在氣頭上居然敢偷打我!!");
                kill_ob(ob);
                }
                break;
        default:
                command("say 滾遠一點!!別煩我!!");
                break;
        }
}

void reset()
{
        delete("memory");
}
