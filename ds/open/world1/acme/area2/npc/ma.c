#include <ansi.h>
inherit NPC;
void create()
{
        set_name("楊大媽",({"yung da ma","ma"}) );
        set("long",
            "她是施府的奶媽，她正在燒著小菜，她長著一頭捲捲的頭髮\n"
            "，臉像一顆蛋般的圓圓肥肥的。\n"
            );
        set("age",30);
        set("race","人類");
        set("level",5);
        set("gender", "女性" );
        set("chat_chance",5);
        set("chat_msg",({
            "楊大媽說道：當心！可別燙著了。\n",
        }));
        setup();
carry_object(__DIR__"eq/boots2")->wear();
}
