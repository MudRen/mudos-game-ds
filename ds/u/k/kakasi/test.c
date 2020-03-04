inherit ROOM;

void create()
{
        set("short", "TEST");
        set("long", @LONG

                       test
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "out" :"/u/k/kakasi/workroom",

]));
 set("item_desc", ([
        "老柳樹" : "上等木材，適於打造家具、房屋用。\n",
        ]));
set("light",1);
        set("objects", ([ /* sizeof() == 2*/
 "/u/k/kakasi/npc/wu" : 1,
 "/u/k/kakasi/npc/ka" : 1,
]));
        set("outdoors","land");
     set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
void init()
{
        add_action("do_beg","beg");
}

int do_beg(string arg)
{
        object me;
        me=this_player();
        if (!arg) return 0;
          if(arg!="老柳樹") return 0;
        if(me->is_busy() || me->is_fighting() )
                return 0;
        else{
                message_vision("$N拜了拜。\n",me);
           me->set_temp("wood",1);
        }
        return 1;
}
