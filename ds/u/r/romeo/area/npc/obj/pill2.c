inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIB"神奇小藥丸"NOR, ({"Msg_Pill","pill"}) );
        set("long",
            "這是一棵更改msg的藥丸.\n"
           );
        set("unit", "顆");
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("base_unit", "顆");
        set("value",30000);
        set("base_weight", 50);
             }
setup();
}
void init()
    {
    add_action("do_eat", "eat");
    }
    int do_eat(string str)
{
    object me;
    object ob;
    string msg_mout,msg_min,msg_home,msg_clone,msg_dest,msg_name,msg_title;
    ob = this_object();
    me = this_player();
    msg_mout = "你使用goto離開這房間時, 這房間的人看到的敘述";
    msg_min = "你使用goto來到這房間時, 這房間的人看的敘述";
    msg_home = "你使用home時的敘述";
    msg_clone = "你使用clone時的敘述";
    msg_dest = "你使用dest時的敘述";
    msg_name = "你的名字";
    msg_title = "你的title";
    if("str == pill")
{
    message_vision(HIB"$N吃下一粒小藥丸！.\n"NOR, me);
    me->set("env/msg_mout",msg_mout);
    me->set("env/msg_min",msg_min);
    me->set("env/msg_home",msg_home);
    me->set("env/msg_clone",msg_clone);
    me->set("env/msg_dest",msg_dest);
    me->set("name",msg_name);
    me->set("title",msg_title);
    destruct(this_object());
    return 1;
}
}

