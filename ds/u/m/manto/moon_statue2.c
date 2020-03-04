#include <ansi.h>
#define SECRET_ROOM "/open/world1/acme/area/moon/room7"
inherit ITEM;
void create()
{
    set_name(HIY"嫦娥雕像"NOR,({"Moon-goddess statue","statue"}));
        set("unit", "座");
        set("long",@LONG
這是月之一族所處月宮的第一任宮主的雕像--嫦娥。仿真的雕刻讓人覺得似乎這個雕像有著生命力。
LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()
{
        add_action("do_kneel","kneel");
}
int do_kneel(string arg)
{
        object me;
        me=this_player();

        if(arg!="statue")
        {
                notify_fail("你往大理石地板亂磕一通撞的頭昏腦脹。\n");
                return 0;
        }
        tell_room(environment(me),me->name()+"虔誠膜拜嫦娥雕像後，彷彿受到她的庇祐。\n",({me}));
        if(CLUB_D->check_member("moon",getuid(me)) > 1 || wizardp(me))
        {
                write("你虔誠膜拜嫦娥雕像後，彷彿受到她的庇祐。\n");
                if(me->can_move(SECRET_ROOM))
                {
                        tell_room(environment(me),me->name()+"突然消失了。\n",({me}));
                        write("忽然有個背著巨大長弓的男人朝你殺過來，你嚇的四處亂跑。\n");
                        me->move(SECRET_ROOM);
                        write("你發現自己莫名其妙來到一個神秘的地方。\n");
                        tell_room(environment(me),me->name()+"像頭野豬一樣沒頭沒腦的衝了過來。\n",({me}));
                        return 1;
                } else
                {
                        write("結果什麼事都沒發生，但是你似乎看到嫦娥嘴角露出了一個微笑!?\n");
                        return 1;
                }
        } else 
        {
                write("你似乎看到嫦娥嘴角露出了一個微笑..\n");
                return 1;
        }
}
