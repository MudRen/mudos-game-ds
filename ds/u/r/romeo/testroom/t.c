inherit ROOM;

void create()
{
        set("short", "kfo���եΪ��p�ж�");
        set("long", @LONG
�@��room,�b��l���@����(kfo)�i�H�ݬݣ��C
LONG
    	    );
         set(hide_exits, ([
                "wiz" : __DIR__"/d/wiz/hall1"
]));
        set("item_desc", ([
                "kfo"      : "�@����kfo�Ү������",
        ]);
void init()
{
        add_action("do_pick", "pull");
}
int do_pick(string arg)
{
        object me;

        me = this_player();
        if ( !arg || ( arg != "kfo" ) ) return notify_fail("�A�n�K����H\n");

        else if ( random((int)me->query("kar")) < 7 )
                message_vision("$N�N��K�F�U�ӡA���@���p�߳Q��F�@�U�C\n", me);

        else
                message_vision("$N�K�U�@�����R��������A��C\n", me);
        return 1;
}
        set("world", "undefine");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);

