// Room: /open/world1/tmr/bagi/area/1f/map_3_7.c
#include <path.h>

inherit ROOM;

void create()
{
        set("short", "�H��}�@�h");
        set("long", @LONG

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"map_4_6",
  "southeast" : __DIR__"map_4_8",
]));
        set("item_desc", ([ /* sizeof() == 2 */
                "����" :"�@�D�سy���Q�����K�����������C\n",
        ]));

        set("objects",([
                __DIR__"npc/jie":1,
                __DIR__"npc/trainee":2,
        ]));
        set("map_long", 1);
        set("current_light", 1);
        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me =this_player();
        if(!arg || arg!="����") return 0;
        if(me->is_fighting() || me->is_busy() )
                return notify_fail("�A�����ۡA�S���Ű��䥦�ơC\n");
        message_vision("$N��۬����ΤO�@���A���M��ӤH�H�۬���½���t�@��h�F�C\n",me);
	me->move(TMR_PAST"bagi/cave1");
        tell_room(me,"�@�}�n�T�L��A$N���M�X�{�b�A���e�C\n",({ me }));
        return 1;
        
}


