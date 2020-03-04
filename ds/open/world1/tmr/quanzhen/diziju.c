// diziju.c �̤l�~
// Winder Oct.10 1998

inherit ROOM;
int do_pull(string arg);

void create()
{
        set("short", "�̤l�~");
        set("long", @LONG
�o�̬O���u�Ч̤l�~���ж��C�ж��ܤj�A����a�Q�ۤ@�Ƥ@��
���ɡA�ɤW�Q�ȳ����|�o�������A���O�@�ӤH���S���A�]�\�Ҧ���
�̤l���h�m�\�h�F�C�a�𪺦a�観�@���d�l(cabinet)�C
LONG
        );
        set("sleep_room",1);
        set("exits", ([
                "north" : __DIR__"jingxiushi",
        ]));
        set("item_desc", ([
            "cabinet": "�@���d�l�A�]�\�O���窫�Ϊ��C\n"
        ]) );
        set("no_clean_up", 0);
	set("coor/x", -2730);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_pull","pull");
}

int do_pull(string arg)
{
        object me=this_player();

        if( !arg || arg != "cabinet" ) {
                return notify_fail("�A�n�Զ}����H\n");
        }

        message_vision("$N�ϫl���d�l�Զ}�A�{�X�@�Ӭ}�f�C��ӳo�̬O�K�Ǫ��J�f�C\n", this_player());
        set("exits/down", __DIR__"mishi");
        remove_call_out("close");
        call_out("close", 8, this_object());

        return 1;
}

void close(object room)
{
        message("vision","�d�l�S�s�s�a�^���a�A��J�f�צ�F�C\n", room);
        room->delete("exits/down");
}