#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIB "殭屍"YEL"犬"NOR, ({"dog"}) );
set("age",10);
set("long","這是一隻從地獄冥界來的地獄犬，全身散發出殺氣，個性無比
的兇殘，遇到它只有逃命喔。\n");
set("attitude", "aggressive");
set("level",15);
setup();
}
