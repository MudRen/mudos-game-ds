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
add_action("do_summon","summon");
    }
int do_summon(string str)
{
        object me = this_player();
        object ob;
        if (!str) return notify_fail("指令格式：Summon <玩家 id>\n");
        ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("沒有這個人。\n");
        if(ob->query("env/god_enable") >= 3) return notify_fail("沒有這個人。\n");       
message_vision(me->query("name")+"("+me->query("id")+")突然派人來召喚$N，$N馬上的被帶走了。\n",ob);
        ob->move(environment(me));
        tell_object(me, "你把"+(string)ob->query("name")+"召到你的面前.\n");
        return 1;
}


