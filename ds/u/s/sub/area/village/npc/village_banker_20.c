// 商人範例(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit BANKMAN;
void create()
{
//=========================基本設定==========================

        set_name("言輕飆", ({ "hoodlum"}));
        set("long",@LONG
眼前是一位臃腫的中年人，他有相當大的啤酒肚，雙眼因為酒色過度
而顯得泛黃。不過你從他的眼神中可以知道他不是一位簡單的人物。

                餘額查詢        <balance>
                存款            <deposit 金額>
                提款            <withdraw 金額>
LONG);
        set("level",20);
        set("title","流氓");
        set("gender", "男性");
        set("race", "human");
        set("age", 50);
        set("evil",100);                //邪惡度 20 (正的表邪惡, 負表善良)
        set("talk_reply","想存錢(deposit)嗎? 常常存款可以避免遺失喔!!");
        set("no_kill",1);
set("inquiry/name", @LONG
有什麼問題找我就對了，我幫你解決！有多餘的錢也可以幫你保管。
LONG );

        setup();
}

void init()
{
 ::init();
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}
