#include <ansi.h>

inherit NPC;

void create()
{
        set_name("小倩", ({ "beauty ghost","ghost" }) );
        set("race","human");
        set("level",28);
        set("age",18);
        set("evil",-20);
        set("long",@LONG
在你面前飄盪的白衣女子朦朦朧朧，形體很模糊，隱約可以
看到她美麗的面龐，因為其美貌為盜賊所垂涎而被害死。
LONG
);
        set("chat_chance",30); 
        set("chat_msg",({
                (:command("sigh"):),
                "小倩慘淡的臉上，偶爾似乎想到了甚麼，忽而露出微笑，忽而嘆息。\n",
                "小倩盯著你瞧，你彷彿聽到她在輕歎。\n",
                "小倩輕輕地呼喚著：「采臣∼∼你在那裡∼∼」\n",
        }) );
        set_skill("unarmed",30);
        set_skill("dodge", 40);
        set_skill("parry", 10);
        setup(); 
        carry_object(__DIR__"../eq/moon_skirt")->wear();
}
