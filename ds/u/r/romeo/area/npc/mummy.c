#include <ansi.h>
inherit NPC;
void create()
{
set_name(WHT "木乃伊"NOR, ({"mummy"}) );
set("age",30);
set("long","一具夏朝實驗用的木乃伊，全身包滿了布條，只能看到眼睛，
但是可不是一般若小腳色喔。\n");
set("attitude", "aggressive");
set("level",20);
setup();
}

