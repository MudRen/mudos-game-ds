inherit ITEM ;
#include <ansi.h>

void create()
{
        set_name(HIW"八極捲軸"NOR,({"bagi scroll","scroll"})); 
        set("unit","條"); 
        set("no_give",1);
        set("no_drop",1);
        set("no_sac",1);
        set("long","隱藏著八極門武功\奧秘的捲軸，你可以打開來看看(open)。\n"); 
        setup();
}
void init()
{
     add_action("do_open","open");
}
int do_open(string arg)
{
    object me=this_player(); 
    if(me->query("level")<45) return notify_fail("你的等級不夠高！\n");
    if( !arg || arg=="" || arg !="scroll" ) return notify_fail("你要打開什麼﹖\n"); 
    { 
    me->start_busy(5); 
    me->set_skill("six_open",1);
    message_vision(HIW"只見一到白光從轉軸裡竄出，$N像是被勾了魂似的...\n"NOR,me);
    tell_object(me,HIW"一道道的武功\招式捲軸出現，你牢牢的記住了這些招式。\n"NOR); 
    write(HIC"你突然對「八極六大開-初」有了更深一層的領悟﹗(提昇至第1級)\n"NOR); 
    }
    return 1;
}
