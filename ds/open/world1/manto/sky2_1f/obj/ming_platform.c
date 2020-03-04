#include <ansi.h>
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
        tell_room(environment(me),HIR""+me->name()+"轉動著聖火標記，四周出現一陣火光。\n"NOR,({me}));
                write(HIR"你轉動著聖火標記，四周出現一陣火光。\n"NOR);
                write(HIR"在熊熊烈燄中，四周的景物開始模糊起來..\n"NOR);
                tell_room(environment(me),HIR""+me->name()+"的身影在火光中一陣模糊。\n"NOR,({me}));

        return 1;
}

