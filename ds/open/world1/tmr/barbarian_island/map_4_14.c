// File: /d/barbarian_island/map_4_14.c
// Updated by tmr (Wed May  8 23:23:58 2002)

inherit ROOM;

void create()
{
          set("short", "�۾��e");
          set("long", @LONG
�X�{�b�A���e���O�@���j�۾��A���W���G���D�H�u�}�ݦӦ����۪��C
LONG
          );
          set("map_long", 1);
          set("outdoors", "forest");
          set("exits", ([ /* 1 element(s) */
        "south" : __DIR__"map_5_14",
]));
        set("detail", ([  // �Odetail ���Odetial , debug by -Acme-
        "�۪�":"�@�D�ݰ_�ӨH�����۪��A�����O�_��̧A���O�q���}��(push)�C\n",
        ]));
        setup();
}
void init()
{
        add_action("do_push","push");
}
int do_push(string arg)
{
        object me=this_player();
        int str=me->query_strength("attack")
		+me->query_stat("nina")*me->query_attr("strength")*10;
        if(!arg || arg!="�۪�")
                return notify_fail("�A�n���ʤ���H\n");
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("�A�����ۡA�Х����U���䪺�Ƨa�C\n");
        if(str<100000) {
                message_vision("$N�ϥX�������O�q�ϫl���n���}�۪��A���O�۪���������.....\n",me);
        } else {
                message_vision("$N���P�a���}�F�۪��A�H�Y���F�i�h......\n",me);
                me->move(__DIR__"statue_room");
                tell_room(environment(me),me->query("name")+"���}�F�۪��A���F�L�ӡC\n",me);
        }
        return 1;
}

