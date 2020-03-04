#include <ansi.h>
inherit NPC;
inherit BANKMAN;
inherit SSERVER;

void create()
{
//=========================基本設定==========================

        set_name( "金開", ({ "jin-kai boss","jin","jai","boss"}));
        
        //tmr, long你自己改改吧. 配點eq..
        set("long", "一個穿金戴銀的微胖中年人，一臉副氣，也是這間錢莊的主人。\n"
        );
        
                set("no_kill",1);       // 不能被殺

        set("level", 4);
        set("gender", "男性");
        set("race", "人類");
        set("age", 30);
        set_skill("blade",40);          // 技能(自定)
        set_skill("parry",40);          //
        set_skill("dodge",40);          //
           set("attitude", "peaceful");   //溫和的 NPC。
           set("talk_reply","想存錢(deposit)嗎? 常常存款可以避免遺失喔!!");

          set("chat_chance", 3 );  //動作機率
          set("chat_msg", ({       //動作內容
        (: command("walk") :),
        }) );
  

        setup();

        add_money("gold", 1);          
}

void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}

