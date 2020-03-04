// Room: /open/world1/tmr/wujian/room2.c

inherit ROOM;

void create()
{
        set("short", "�L���p�D");
        set("long", @LONG
������@���A�b���·t���}�ޤ��A���G���ط������ƪ��ͪ��A
�F�F���n�T���_���o�X�C��o��w�g�O���Y�F�A�A�`�N�e��������D
�t��A�b�@�����������{�A�t��W�f���G���D�����C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room1",
]));
        set("item_desc",([      
        "�t��" : "�@�D�ѵM�Φ����t��A�A�i�H��(climb)�W�h�ݬݡC\n",
        ])      );

        set("no_clean_up", 0);
        set("current_light", 4);

        setup();
}



int do_climb(string arg)
{
        object me;
        if(!arg || arg != "�t��") return notify_fail("�A�Q�n������H");
        me=this_player();
        if(me->is_busy()) return notify_fail("�A�W�@�Ӱʧ@�٨S�����C\n");
        message_vision("$N���W�t��A�S�X�B�N�S�J�@�������F�C\n",me);
        me->move("/open/world1/jangshow/flame_area/room");
        return 1;
}

void init()
{
 add_action("do_climb","climb");
}
