#include <ansi.h>
#define SECRET_ROOM "/open/world1/acme/area/moon/room8"
inherit ITEM;
void create()
{
    set_name(HIC"嫦娥雕像"NOR,({"Moon-goddess statue","statue"}));
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
        add_action("do_worship","worship");
}

int do_worship(string arg)
{
        object me;
        me=this_player();

        if(arg!="statue" && arg!="moon-goddess statue")
        {
                notify_fail("你往大理石地板亂磕一通撞的頭昏腦脹。\n");
                me->start_busy(1);
                return 0;
        }
        tell_room(environment(me),HIC+me->name()+"虔誠膜拜嫦娥雕像後，彷彿受到她的庇祐。\n"NOR,({me}));
        if(CLUB_D->check_member("moon",getuid(me)) > 1 || wizardp(me))
        {
                write(HIC"你虔誠膜拜嫦娥雕像後，彷彿受到她的庇祐。\n"NOR);
                if(me->can_move(SECRET_ROOM))
                {
                        tell_room(environment(me),HIG+me->name()+"突然消失了。\n"NOR,({me}));
                        write(HIR"忽然有個背著巨大長弓的男人朝你殺過來，你嚇的四處亂跑。\n"NOR);
                        me->move(SECRET_ROOM);
                        write(HIW"你發現自己莫名其妙來到一個神秘的地方。\n"NOR);
                        tell_room(environment(me),me->name()+"像頭野豬一樣沒頭沒腦的衝了過來。\n",({me}));
                        return 1;
                } else
                {
                        write(CYN"結果什麼事都沒發生，但是你似乎看到嫦娥嘴角微微上揚了一下!?\n"NOR);
                        return 1;
                }
        } else 
        {
                write(CYN"你似乎看到嫦娥嘴角微微上揚了一下..\n"NOR);
                return 1;
        }
}

