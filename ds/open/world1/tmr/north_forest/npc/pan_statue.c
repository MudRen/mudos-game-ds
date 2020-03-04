inherit ITEM;

void create()
{
        set_name("破損的石像", ({ "breakage statue", "statue" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long",@LONG
這是一座破損的石像，依稀還可以認的出是牧神潘恩的石像。
石像頭上有著一對山羊角，臉上長著山羊鬍，有著人類的上半身
，下隻卻是兩條山羊。你還注意到石像因為長年的風吹雨打，臉
上的石眼(look eye)已經搖搖欲墜了。
LONG
);

                set("value", 1);
                set("no_get",1);
                  set("no_sac",1);
        }
}

void init() {
        add_action("do_look","look");
        add_action("do_install","install");
}

int do_look(string arg) {
          if( arg != "石眼" && arg != "eye") return 0;
        tell_object(this_player(), "你看石眼雖然破損的很嚴重，但似乎還可以裝(install)的回去。\n" );
        return 1;
}

int do_install(string arg) {
        if( arg != "石眼" && arg != "eye" ) return notify_fail("你想要裝什麼東西？\n");
        if( this_player()->is_busy()) return notify_fail("你正忙著，沒有空做這件事。\n");
        message_vision("$N好心將破損石像上的石眼扶正，裝了回去。\n", this_player() );
        this_player()->set_temp("enter_goat_maze",1);   // 可以進入羊男的迷宮
        this_player()->start_busy(1);
        return 1;
}

