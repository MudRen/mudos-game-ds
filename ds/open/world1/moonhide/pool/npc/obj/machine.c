#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"對換機"NOR,({"change machine","machine"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "台");
                set("long",
               "新手所使用的機器，只要拿著經驗票，放到對換機的水盆裡，就可以換到經驗值喔！(change ticket from machine)。\n");
             }
        set_weight(999999);     
        set("no_get",1);
        set("no_sac",1);
        setup();
} 
void init()
{
     add_action("do_change","change");
}
int do_change(string arg)
{
    object me,ob;
    me = this_player();
    if(!arg || arg!="ticket from machine") return notify_fail("你要換什麼?\n");
    if(!objectp(ob = present("exp ticket",me) ) )
    return notify_fail("你沒有票可以對換喔!\n");   
    
    {
    message_vision(HIM"$N把經驗票放在對換機上的水裡。\n"NOR,me);  
    destruct(ob);    
    tell_object(me,"你得到 500 經驗值！\n");
    tell_object(me,"因為你對換的經驗值，所以你暫時不能動 20 回合\n");
    me->start_busy(20);
    me->add("exp",500);      
    
    } 
    return 1;
}

