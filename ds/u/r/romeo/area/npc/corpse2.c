#include <ansi.h>
inherit NPC;
void create()
{
set_name(GRN "膿屍"NOR, ({"corpse"}) );
set("age",30);
set("long","這一具屍體也是感受到秦始皇的魔力，再加上自已死前的一股怨氣
而再生，但是因為時光久遠，屍體已經腐爛流膿了，讓人覺得更是
難過。\n");
set("attitude", "aggressive");
set("level",15);
setup();
}

