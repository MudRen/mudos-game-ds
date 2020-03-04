#include <ansi.h>
#define SECRET_ROOM "/open/world1/baal/ming_club/mingsaint"
inherit ITEM;
void create()
{
    set_name(HIR"聖火台"NOR,({"The Platform of Holy Fire","platform"}));
        set("unit", "座");
        set("long",@LONG
上面有一聖火標記(fire)好像可以轉動(turn)
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
        add_action("do_turn","turn");
}

int do_turn(string arg)
{
        object me;
        
        me=this_player();
        if(arg!="platform")
        {
                notify_fail("你要轉什麼?\n");
                return 0;
        }
        tell_room(environment(me),me->name()+"轉動著聖火標記，四周出現一陣火光。\n",({me}));
        if(CLUB_D->check_member("ming",getuid(me)) > 4 ||CLUB_D->check_member("sky",getuid(me)) >3|| wizardp(me))
        {
                write("你轉動著聖火標記，四周出現一陣火光。\n");
                if(me->can_move(SECRET_ROOM))
                {
                        tell_room(environment(me),me->name()+"在火光中消失了。\n",({me}));
                        write("在熊熊烈燄中，四周的景物開始模糊起來..\n");
                        me->move(SECRET_ROOM);
                        write("你來到明教聖地。\n");
                        tell_room(environment(me),me->name()+"突然出現在這裡。\n",({me}));
                        return 1;
                } else
                {
                        write("你轉動聖火標記，什麼是都沒發生。\n");
                        return 1;
                }

        } else 
        {
                write("你轉動聖火標記，什麼是都沒發生。\n");
                return 1;
        }
}

