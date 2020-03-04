// shantang.c
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�o�̬O���u�Ъ�����A�O�̤l�̥��\���a��C�o�Ӱ�ܤj�A
����a�\��ۤ@�Ƥ@�ƪ���ȡC�{�b��ȤW�T�T���a���ۥ��u
�̤l�A�������b���\�A�����C�Y�ͯ��C�ݵۥi�f������A�A�Ԥ�
��]�Q�s(order)�@���C
LONG
        );
        set("exits",([
                "north" : __DIR__"xiuxishi",
                "east" : __DIR__"chufang",
                "northwest" : __DIR__"wuchang2",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2740);
	set("coor/y", 80);
	set("coor/z", 170);
	setup();
}

void init()
{
        add_action("do_order","order");
}

int do_order(string arg)
{
        object me=this_player();
        object food;
        object water;

        if (arg)  return notify_fail("�o�˪F��o�̨S���ڡC\n");
        if (me->query("family/family_name") != "���u��")
        {
              message_vision("���u�D�H�ĥX�ӡA���F$N�@���G���A���̨Ӫ��I���ӲV���Y�I��\n",me);
              return 1;
        }

        if ((present("bowl",this_player()) || present("rice",this_player())))
              message_vision("���u�D�H�ĥX�ӡA���F$N�@���G���٨S�Y���S�Q�n�I��\n",me);
        else
        {
              message_vision("���u�D�H�s���q�p�ХX�ӡA��@�J�̶��M�@�J�����F��$N�C\n",me);
              food=new(__DIR__"obj/rice");
              water=new(__DIR__"obj/bowl");
              food->move(me);
              water->move(me);
        }
        return 1;
}

int valid_leave(object me,string dir)
{
        me=this_player();
        if(( dir=="north" || dir=="northwest")
        && (present("bowl",this_player()) || present("rice",this_player())))
             return notify_fail("���u�D�H���D�G�����M��������a�X����h�C\n");
        return ::valid_leave(me,dir);
}