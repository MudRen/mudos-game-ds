inherit ITEM ;
#include <ansi.h>

void create()
{
        set_name(HIC"無月寶盒"NOR,({"message item","item"}));
        set("unit","個");
        set("base_unit","個");
        set("needaward",1);  
        set("no_give",1);
        set("no_drop",1);
        set("no_sac",1);
set("long","Jangshow的專屬訊息用品。\n");
        setup();
}

void init()
{
        add_action("do_showmsg","showmsg");
}

int do_showmsg(string arg)
{
        object me = this_player();
        if( !arg || arg=="" ) return notify_fail("你要寫什麼﹖\n");
        message_vision(CYN"\n$N開起無月寶盒，向裡面喃喃自語。\n"NOR,me);
message_vision(HIR"\n一陣光從無月寶盒裡竄出，直上天際！。\n"NOR,me);
        tell_object(users(),
        HIC"\n\t"+arg+"\n\n"NOR);
    return 1;
}
int query_autoload() { return 1; }

