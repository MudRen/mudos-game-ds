// Room: /open/world1/tmr/gumu/xiaoting.c

inherit ROOM;

void create()
{
        set("short", "小廳");
        set("long", @LONG
這里是一個小小的廳堂。你走到這里，周圍的光線亮了一些，你發
覺壁上燃點著一些油燈。廳里的布置整潔而不簡陋，一桌一椅都收拾的
井井有條。南面有一扇石門(door)。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "door" : "一扇厚重的石門，光溜溜的全沒有把手。你認真看了看，發現門邊的石壁上似乎有什麼按鈕(press button)可以開門。
",
]));
        set("current_light", 1);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mudao09e",
  "east" : __DIR__"mudao12",
]));

        setup();
}


void init()
{
        add_action("do_an", "press");
}

int do_an(string arg)
{
        object room, me = this_player();

        if( !arg || arg != "button" )
        {
                message_vision("你在石壁上亂按一氣，除了一手灰，啥也沒摸著。\n", me);
                return 1;
        }
        if( query("exits/south"))
        {
                return notify_fail("石門已經是開著了。\n");
        }
        if( me->query_skill("unarmed", 1) > 10)
        {
                message_vision("$N站在石門前，也不知在哪里按了一下，石門吱吱響著，緩緩打開了。\n", me);
                if( !(room = find_object(__DIR__"mudao11")) )
                        room = load_object(__DIR__"mudao11");
                set("exits/south", __DIR__"mudao11");
                room->set("exits/north", __DIR__"xiaoting");
                tell_room(room,"只聽得石門在吱吱聲中被緩緩打開。\n");
                remove_call_out("close");
                call_out("close", 5, me);
        }
        else
                message_vision("$N試著在石壁上按來按去，可是石門紋絲不動，只得罷了。\n", me);
        return 1;
}

void close(object me)
{
        object room;

        tell_room(this_object(), "石門緩緩地關上，恢復了原狀。\n");
        delete("exits/south");
        if( !(room = find_object(__DIR__"mudao11")) )
                room = load_object(__DIR__"mudao11");
        room->delete("exits/north");
        tell_room(room,"北牆的石門緩緩地關上了。\n");
}

