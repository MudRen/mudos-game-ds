inherit NPC;

void create()
{
        set_name("漁民",({"fisher"}));
        set("long",@LONG
一位皮膚黝黑的漁民，正在一邊忙著。
LONG);
        set("race","人類");
        set("gender", "男性");  
        set("age",25+random(10));
        set("level",16+random(4));
        set("attitude","friendly");
        set("chat_chance",10);
        set("chat_msg",({
        "漁民一邊整理漁網，一邊檢視有沒有破洞。\n",
        "漁民將竹簍中處理好的魚，一隻隻吊在竹竿上製成魚干。\n",
        "漁民將一簍空的貝殼倒在路旁，發出喀啦喀啦的聲響。\n",
        }));
        setup();
        add_money("coin",100+random(100));
}
