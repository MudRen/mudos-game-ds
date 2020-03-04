#include <ansi.h>
#define SECRET_ROOM "/open/world1/acme/area/moon/room8"
inherit ITEM;
void create()
{
    set_name(HIR"楓的骷髏\頭"NOR,({"The Skeleton Of Fofo","skeleton"}));
        set("unit", "座");
        set("long",@LONG
                          ▃▅▇██▇▅▃
                        ▇████████▇
                       ███████████
         ▄          ██▄███████▄██
         ▍         ███      ██     ███
         █        ▌█         █         ██
         ▄         █                       █
      ▄ ▄ ▄ ▃  █                       █
      ▌ ▌ ▌ ▅   █          █          █
   ▄█▌█ █ ▌   █▄     █  █     ▄█
  █▄▄▄▄▄▄▄   ▃ █▄█      █▄█ ▃
 █ █ █ █ █ █    █▄██      █▌▄█
  ▌███████      █ ██    ▌▌ █
 █ ██████        █  ▌▌▅ ▌▌ █
    ████▃▌        █            █
      █▃ ██           █ ▌▌ ▌▌█
      ██ ██              ████

這是楓(Fofo)怕自己死無全屍事先做的的模型骷髏頭，假的極可亂真
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
        add_action("do_touch","touch");
}

int do_touch(string arg)
{
        object me;
        
        me=this_player();
        if(arg!="skeleton")
        {
                notify_fail("你要摸什麼?\n");
                return 0;
        }
        tell_room(environment(me),me->name()+"觸摸了一下楓的骷髏\頭。\n",({me}));
        if(CLUB_D->check_member("moon",getuid(me)) > 1 || wizardp(me))
        {
                write("你忍不住觸摸了一下楓的骷髏\頭。\n");
                if(me->can_move(SECRET_ROOM))
                {
                        tell_room(environment(me),me->name()+"突然消失了。\n",({me}));
                        write("忽然四周陰風陣陣吹..\n");
                        me->move(SECRET_ROOM);
                        write("你發現自己來到一個神秘的地方。\n");
                        tell_room(environment(me),me->name()+"突然出現在這裡。\n",({me}));
                        return 1;
                } else
                {
                        write("結果什麼事都沒發生..你覺得似乎不太對勁。\n");
                        return 1;
                }

        } else 
        {
                write("你感覺骷髏\頭似乎對你笑了一下...恐怖ㄡ~~~\n");
                return 1;
        }
}

