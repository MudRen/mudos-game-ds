#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("東西", ({"test"}));
    set("unit", "個");
    set("long",@LONG
    用來玩的一個東西
LONG);

    set_weight(1);
    set("value",1);
  setup();
}

void init()
{
add_action("do_io","io");
    }
int do_io(string arg)
{
        object me = this_player();
         int i;
me->set("long",
HIC"╭╮      ╭───╮╭───╮╭───╮╭───╮╭───╮\n"
NOR""CYN"││      │╭──╯│╭──╯╰╮  ╭╯╰╮  ╭╯│╭─╮│\n"
HIC"││      │╰─╮  │╰──╮  │  │    │  │  ││  ││\n"
NOR""CYN"││  ╭╮│╭─╯  ╰──╮│  │  │    │  │  │╰─╯│\n"
HIC"│╰─╯││╰──╮╭──╯│  │  │  ╭╯  ╰╮│╭─╮│\n"
NOR""CYN"╰───╯╰───╯╰───╯  ╰─╯  ╰───╯╰╯  ╰╯\n"NOR);
       return 1;
}

