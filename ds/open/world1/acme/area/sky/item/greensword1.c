#include <ansi.h>
#define OUT_ROOM "/open/world1/acme/area/sky/room05"
inherit ITEM;
void create()
{
    set_name(HIG"碧綠長劍"NOR,({"green sword","greensword","sword"}));
        set("unit", "個");
        set("long",@LONG
一把碧綠色的長劍，劍身直插入地臺直至沒柄。如果你向它虔誠
祈禱(pray)的話，說不定會有甚麼奇妙的事情發生。

LONG
);
        set_weight(999999);
        set("material","steel");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()
{
        add_action("do_pray","pray");
}

int do_pray(string arg)
{
        object me;
        
        me=this_player();
        if(arg!="green sword" && arg!="greensword" && arg!="sword" )
        {
                notify_fail("你要對什麼禱告?\n");
                return 0;
        }

        if(CLUB_D->check_member("sky",getuid(me)) >= 5 ||CLUB_D->check_member("ming",getuid(me)) >=5|| wizardp(me))
        {
                message_vision(HIG"$N誠心的向碧綠色長劍祈禱，一片碧綠色的光芒圍繞著$N。\n"NOR,me);
                if(me->can_move(OUT_ROOM))
                {
                        tell_room(environment(me),me->name()+"漸漸消失的無影無蹤了。\n",({me}));
                        me->move(OUT_ROOM);
                        write(HIG"  你眼前的綠光慢慢地消失，而你發覺你已經身在【長老房間】了。\n"NOR);
                        tell_room(environment(me),HIC"突然間一陣刺眼光芒，"+me->name()+HIC"隨著光芒出現於此地。\n"NOR,({me}));
                        return 1;
                } else
                {
                        write("結果什麼事都沒發生..你覺得似乎不太對勁。\n");
                        return 1;
                }
        }
         else
        {
                message_vision("$N誠心的向碧綠色長劍祈禱。\n",me);
                write(HIC"碧綠長劍似乎閃動了一下，隨即又回復了原狀。\n"NOR);
                return 1;
        }
}

