inherit ROOM;

void create()
{
        set("short", "���O");
        set("long", @LONG
�A���B�b���ê����O�̡A�a�W�ٯd�ۤ@�ﰮ�\���e���A�e���W�`�`��
��۳��~�����A�|�P����{���V�X�ۤ@�ѱ���A�O�H�����[�ݡC
LONG
        );
set("exits", ([ /* sizeof() == 1 */
      "west" : __DIR__"lea15",
]));
        set("no_clean_up", 0);
     set("item_desc", ([
            "���O" : "�A�J���@�F�@���O�A�o�{���O�̦��@�褭�����߯�C\n",
            "�������߯�" : "�A�J���@�F�@�������߯�A�γ\\�A�i��K(pick)�U���C\n",
     ]) );      
     set("outdoors","land");
     set("objects", ([
        __DIR__"npc/lion" : 2,
     ]) );
        setup();
}
void init()
{
    add_action("do_pick","pick");
}
int do_pick(string arg)
{
        object herb;
        object me;
        me=this_player();
        if(query_temp("herb1")) return notify_fail("����H\n");
        if(arg != "�������߯�")
        {
            notify_fail("�A�n�K�U����H\n");
            return 0;
        }
        else {
       message_vision("$N�p���l�l���N�������߯�K�F�U�ӡC\n",me);
        herb=new(__DIR__"obj/herb.c");
        herb->move(me);
     set("item_desc", ([
            "���O" : "�A�J�ӧ�F����O�A���G����]�S�o�{�C\n",
     ]) );      
     set_temp("herb1",1);
        call_out("delay",600,this_object());
        return 1;
             }
}
void delay(object room)
{
     delete_temp("herb1");
     set("item_desc", ([
            "���O" : "�A�J���@�F�@���O�A�o�{���O�̦��@�]�������߯�C\n",
            "�������߯�" : "�A�J���@�F�@�������߯�A�γ\\�A�i��K(pick)�U���C\n",
     ]) );      
}
