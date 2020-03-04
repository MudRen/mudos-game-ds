inherit NPC;

void create()
{
        set_name("吊死鬼", ({ "hanged ghost","ghost" }) );
        set("race","human");
        set("gender", "男性");
        set("level",17);
        set("attitude","aggressive");
        set("age",180);
        set("evil",5);
        set("long",@LONG
上吊而死的鬼魂，長長的舌頭顯得沒有血色，上吊時的繩子
，仍掛在脖子上，紫黑色的腫塊在繩子周圍依舊非常明顯。
LONG
);
        set("chat_chance",10); 
        set("chat_msg",({
                "吊死鬼伸長舌頭, 想說甚麼卻說不出。\n",
                "吊死鬼用惡狠狠的眼光睨視著你。\n",
        }) );
        setup(); 
}

