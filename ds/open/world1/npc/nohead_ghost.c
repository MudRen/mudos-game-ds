#include <ansi.h>

inherit NPC;

void create()
{
        set_name("無頭鬼", ({ "nohead ghost","ghost" }) );
        set("race","human");
        set("gender", "男性");
        set("level",14);
        set("attitude","aggressive");
        set("age",300);
        set("evil",1);
        set("long",@LONG
不知什麼原因而被斬首的無頭鬼, 死後唯一的願望就是, 找回
自己的頭, 因此飄游在人間。
LONG
);
        setup(); 
}

