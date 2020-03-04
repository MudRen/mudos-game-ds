// File: /d/duli_village/map_6_2.c
// Updated by tmr (Fri May  3 19:34:42 2002)

inherit ROOM;

void create()
{
          set("short", "������f��");
          set("long", @LONG
���Ū����v���b�A���e�H�ۤӶ������y�ۡA�A�ۭt�n��(dive)�U���v
�����A�ˤ]�٦��������ʩM��O�C
LONG
          );
          set("exits", ([ /* 1 element(s) */
        "east" : __DIR__"map_6_3",
]));
          set("outdoors", "forest");
          set("map_long", 1);
         set("objects",([
           __DIR__"npc/wang-feng":1,
           ]) );



        setup();
}

void init()
{
        add_action("do_dive","dive");
}

int do_dive(string arg)
{
        object me=this_player();
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("�A�����ۡA�S�ż���C\n");
        message_vision("�u�P�q�v�@�n�A$N�D�������A�H�Y�穹���v���U�F....\n",me);
          me->move(__DIR__"sea_room");
        tell_room( environment(me),me->query("name")+"�q�����W��F�L�ӡC\n",me );
        return 1;
}


