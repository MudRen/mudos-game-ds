//oceaner.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("大學男孩",({"play boy","boy"}));
set("level",25);
set("age",21);
set("long","一個無所事是的青年人, 一對賊眼不斷的瞄著路過的漂亮美眉。\n");
set("gender", "男性");

        setup();
carry_object(__DIR__"book");
}
