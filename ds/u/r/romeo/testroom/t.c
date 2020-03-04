inherit ROOM;

void create()
{
        set("short", "kfo測試用的小房間");
        set("long", @LONG
一間room,在桌子有一朵花(kfo)可以看看ㄛ。
LONG
    	    );
         set(hide_exits, ([
                "wiz" : __DIR__"/d/wiz/hall1"
]));
        set("item_desc", ([
                "kfo"      : "一朵由kfo所栽培的花",
        ]);
void init()
{
        add_action("do_pick", "pull");
}
int do_pick(string arg)
{
        object me;

        me = this_player();
        if ( !arg || ( arg != "kfo" ) ) return notify_fail("你要摘什麼？\n");

        else if ( random((int)me->query("kar")) < 7 )
                message_vision("$N將花摘了下來，但一不小心被刺了一下。\n", me);

        else
                message_vision("$N摘下一朵美麗的血紅色鮮花。\n", me);
        return 1;
}
        set("world", "undefine");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);

