#include <ansi.h>

inherit ITEM;

void create()
{
     set_name(HIR"龍蝦炸球-.-"NOR, ({"BOMB", "bomb"}));
     set_weight(0);
     set("unit", "隻");
     set("long", "請勿摸(touch)我我會咬人。\n");
     set("value", 1);
     set("type", "misc");
     set("no_get", 1);
}

void init()
{
     add_action("do_touch","touch");
}

void delay_grin()
{
     tell_object(this_player(), "\n看吧闖禍了齁 -.- 誰叫你手賤不聽話 -.-\n");
destruct(this_object());
     return;
}

int do_touch(string arg)
{
    if(!arg || arg != "bomb") return notify_fail("你要摸什麼東西 ?\n");
    this_player()->set("hp", 1);
    message("system", HIR"轟∼∼∼∼你的身體被炸成一萬片∼∼轟\n"NOR, users());
    this_object()->move(this_player());
    call_out("delay_grin", 5);
    destruct(environment(this_player()));
    return 1;
}

