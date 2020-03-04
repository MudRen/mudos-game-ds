// Room: /open/world1/tmr/advbonze/hill16.c

inherit ROOM;

void create()
{
        set("short", "�ⶳ�p-�W�ѱ�ʤf�B");
        set("long", @LONG
�A�����b�W�ѱ誺�@�B�ʤf�B�A�A�M���ݨ�W�ѱ�즹���ᳺ�M��
�F�@�Ӥj�_�f�A�Z�����_�f���_���Q�ƤV�~�~����t�@�B�_�f�A�G�ӯ�
�f�����צp�j�F�Ӥj�a�V�@�ǡA�y�@�����A�N���i�ઽ�L��s���̡A�A
���T�Ҽ{�ۦۤw�����\�y�ڡA�O�_���(jump)���L�h�C
LONG
        );
        set("current_light", 5);
        set("no_clean_up", 0);
        set("outdoors", "forest");
        set("exits", ([ /* sizeof() == 1 */
          "southdown" : __DIR__"hill15",
        ]));
        set("item_desc", ([
          "�ʤf" : "�@�ӤQ�X�V���e���j�ʤf�A�A�i�H�ݭⶳ�p�s�y�U�����p�C\n"
        ]));

        setup();
}

void init()
{
    ::init();
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me=this_player();        
        if(arg!="�ʤf") 
                return notify_fail("�A�Q�n��(jump)�L����H");
        if(me->is_busy() )
                return notify_fail("�A�����ۡA�L�k�M�����I���ʧ@�C\n");
          if(me->query_skill("dodge") < 10)
                return notify_fail("�A�����\\�y�ڤ����A�A�L�k�w���a���L�h�C\n");
        if(!me->move(__DIR__"hill17.c") )
                return notify_fail("�A�L�k���L�ʤf�C\n");
        tell_room(environment(me), me->name()+"�@������L�F�ʤf�A�������a���b�a�W�C\n");

        return 1;

}


