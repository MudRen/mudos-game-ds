#include <ansi.h>

inherit ITEM;

void create()
{
     set_name(HIR"�O�I�ڧگu���ܦM�I -.-"NOR, ({"BOMB", "bomb"}));
     set_weight(0);
     set("unit", "��");
     set("long", "�ФźN(touch)�ڡC\n");
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
     tell_object(this_player(), "\n�ݧa���פF�� -.- �֥s�A��⤣ť�� -.-\n");
destruct(this_object());
     return;
}

int do_touch(string arg)
{
    if(!arg || arg != "bomb") return notify_fail("�A�n�N����F�� ?\n");
    this_player()->set("hp", 1);
    message("system", HIR"�F�����A������Q�����@�U������F\n"NOR, users());
    this_object()->move(this_player());
    call_out("delay_grin", 5);
    destruct(environment(this_player()));
    return 1;
}



