#include <ansi.h>
inherit NPC;
void create()
{
        set_name("女宣傳人員", ({"woman"}) );
        set("long", "這是食品街的女宣傳人員。\n");
        set("race", "人類");
        set("age", 17);
        set("level", 15);
        set("chat_chance", 10);
        set("chat_msg", ({
                HIY"”大家好，世界食品街新開幕，多謝大家支持！”\n"NOR,
                HIY"”多種世界美食都在食品街內，大家快試試吧！”\n"NOR,
        }));
setup();
}
