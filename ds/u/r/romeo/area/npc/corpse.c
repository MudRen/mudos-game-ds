#include <ansi.h>
inherit NPC;
void create()
{
set_name(WHT "腐屍"NOR, ({"corpse"}) );
set("age",30);
set("long","這具腐屍是感受秦始皇的魔力所引，腐肉的味道傳到你的鼻子裡，
哇！真臭ㄚ。\n");
set("attitude", "aggressive");
set("level",17);
setup();
}
