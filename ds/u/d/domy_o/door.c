#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�_�Ǫ��Ѥf");
        set("long", @LONG
    �A���b�@�ө_�Ǫ��Ѥf�W�A����W���G���}�f��i�h
LONG
        );
      set("item_desc", (
        "���" : "�@�ө_�Ǫ��}�f, ���O����o���i�h�C\n",
        "�}�f" :"�@�ө_�Ǫ��}�f, ���O����o���i�h�C\n",
        ]));

        set("no_clean_up", 0);
        set("outdoors","land");

        setup();
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me;
        me=this_player();

        if (arg != "�}�f" && arg !="hole" )
                return 0;
        else 
        {
        message_vision("$N¬�}�F����A���F�i�h�C\n",me);
        me->move(__DIR__"workroom");
      tell_room(environment(me),me->query("name")+"¬�}�F����A���F�i�h\n",me);
        return 1;

}

