inherit ROOM;
void create()
{
        set("short", "�L���p��");
        set("long", @LONG
�@�ʾ֦��ʦ~���֪��Ѭh���b�������A�Ѿ�W����K���C���K����
�n�V�W���ѯ몺�W���ӤW�C�A�`�N�즳�ڲʦp�H�u����K�N�b���A�Y
���������a��C
LONG
);
        set("exits",([
        "south" : __DIR__"map_7_7",
        "east" : __DIR__"map_6_8",
        ]));
        set("detail",([
                  "��K":"�@�ھ�b�A�Y���W�誺�ʾ�K�A�A�ۭt�ٯ��(jump)���W�h�C\n",
        ]));
        set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
}
void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me=this_player();
        if(!arg || arg!="��K" )
                return notify_fail("�A�n���줰��a��H\n");
        if(me->is_busy())
                return notify_fail("�A�����ۡA�S���Ű��o�Ӱʧ@�C\n");
        message_vision("$N�������a���W�j��W���@�I��K�C\n",me);
        me->move(__DIR__"three");
        return 1;
}

