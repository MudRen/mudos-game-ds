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
        "�Ѭh��" : "�W������A�A�󥴳y�a��B�ЫΥΡC\n",
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
          if(arg!="�Ѭh��") return 0;
        if(me->is_busy() || me->is_fighting() )
                return 0;
        else{
                message_vision("$N���F���C\n",me);
           me->set_temp("wood",1);
        }
        return 1;
}
