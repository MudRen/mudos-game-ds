#include <ansi.h>
inherit NPC;
void create()
{
        set_name("家丁", ({ "guard" }) );
        set("gender", "男性" );
        set("long",
            "一個看管著施府大門的家丁。\n"
           );
        set("age",45);
        set("level",10);
        set("chat_chance", 2);
        set("chat_msg", ({
                "家丁說道：這幾天許\多人來找老爺，不知所為何事？\n"
                "家丁說道：是啊！就連各派長老也來了！\n"
        }));

        set("chat_chance_combat",90);
        set("chat_msg_combat", ({
                "家丁咆哮道：惡賊！去死吧！\n",
         }) );
        setup();
}
