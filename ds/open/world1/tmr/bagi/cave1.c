// Room: /open/world1/tmr/bagi/cave1.c

inherit ROOM;

void create()
{
        set("short", "�s�}��");
        set("long", @LONG
�A�����b�����}���}�f�B�A���~�Y�i���}�o�ө��}�C���O�b���s���W
�A���o��w�g����������n���A�P�D���ūפ]�S���}�~������ŴH�A�ݼ�
�l�b�o�����׭����]���L�p�i�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"ghat13",
]));
        set("no_clean_up", 0);
        set("item_desc", ([ /* sizeof() == 2 */
  "�譱�۾�" :@long
�o���۾�����A�M�䥦�T���������P�A�ѩ�}�����¡A�A�@�ɤ]�@��
�M�A�γ\�i�H�յ۸IĲ(touch)�ݬݡC
long
,
]));
        set("current_light", 3);
        setup();
}

void init()
{
        add_action("do_touch","touch");
        add_action("do_push","push");
}

int do_touch(string arg)
{
        object me=this_player();
        if(!arg || arg!="�譱�۾�") return 0;
        message_vision("$N���X�����ۥ۾��V�V����.....\n",me);
        tell_object(me,"�A�oı�o���۾����G�O�@�D�i�H���}�������I�H\n");
        return 1;
}

int do_push(string arg)
{
        object me =this_player();
        if(!arg || arg!="�譱�۾�") return 0;
        if(me->is_fighting() || me->is_busy() )
                return notify_fail("�A�����ۡA�S���Ű��䥦�ơC\n");
        message_vision("$N��ۥ۾��ΤO�@���A���M��ӤH�H�ۥ۾�½���t�@��h�F�I�I�H�H\n",me);
        me->move(__DIR__"area/1f/map_3_7.c");
        tell_room(me,"�@�}�n�T�L��A$N���M�X�{�b�A���e�C\n",({ me }));
        return 1;
        
}

