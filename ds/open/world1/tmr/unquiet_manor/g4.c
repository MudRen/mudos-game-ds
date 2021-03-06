#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "無寧之墳-墓道盡頭");
        set("long", @LONG
你正在走無寧莊園的地下墓道中，墓穴屍氣幾百年不曾流動，你
只吸入幾口就已覺得頭昏腦脹，只想要趕快離開這個地方。墓道中沒
沒有一絲光線，靜默的氣氛悄悄然帶來絕望的恐懼感。你已經走到墓
道的盡頭了，佇在你面前的是道刻有古字的墓門。
LONG
        );
        set("item_desc", ([
                "墓門": "墓門上刻著上古時期的文字，你半個字也認不得。你注意到墓門似乎可以推動(push)\n"NOR,
        ]));

        set("exits", ([ /* sizeof() == 2 */
         "north" : __DIR__"g5",
]));
        set("no_clean_up", 0);
        set("current_light", 4);

        setup();
}



void init()
{
        add_action("do_tui", "push");
}

int do_tui(string arg)
{
        object me = this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙著哪！\n");
        if (arg !="墓門")
                return notify_fail("你要推什麼？\n");
                
        message_vision(GRN "$N雙手推開墓門，咯吱吱響起，墓門緩緩移開。\n"NOR,me);
        set("exits/out", __DIR__"g3");
        remove_call_out("close");
        call_out("close", 5);
        return 1;
}

void close( )
{
        tell_room(this_object(), GRN"墓門慢慢移了回來，恢復了原狀。\n"NOR);
        delete("exits/out");
}
