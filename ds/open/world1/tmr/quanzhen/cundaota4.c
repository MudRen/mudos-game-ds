// cundaota4.c �s�D��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_dian(string arg);

void create()
{
        set("short", "�s�D��");
        set("long", @LONG
�o�̬O�s�D�𪺶𳻡A����o�̴N��F���Y�C����W�}�۴X
�ӵ���(window)�A�@�Ӥ��~�D�H�����ۤ@���ѭW�W��Ū�C�Ѧ���t�A
��W�\��ۤ@������(candle)�A�o�S���I�ۡC
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"cundaota3",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/zhangjing" : 1,
        ]));

        set("item_desc", ([
        "window": "���~�ն��ƹL�A���G�A�@����N�i�H���@���C\n",
        "candle": "�@�䴶�q������A�w�g�I���u�Ѥ@�p�b�F�C\n"
        ]) );

        set("count",1);
	set("coor/x", -2790);
	set("coor/y", 130);
	set("coor/z", 200);
	setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_dian","dian");
}

int do_dian(string arg)
{
        object ob;
        object me=this_player();

        if (!arg || arg != "candle")
                return notify_fail("�A�n�I�U����H\n");

        if ( query("count")>0 &&
        present("zhangjing", environment(me)) &&
        living(present("zhangjing", environment(me))) ) {
                message_vision(HIG"$N���W�e�h�A���ۤ��������I�U�A�θ̹y�ɫG��F�\�h�C\n"NOR,this_player());
                message_vision("�x�g�D����_�Y�A�n����q�I�䤤��_�L�Ӧ����A�D�G��\n",this_player());
                message_vision("��w�ߤF�ܡA���A��Ū�o���D�w�g���M�s�Ѧ�]�ѰO�F�C\n",this_player());
                message_vision("�n�A�h�³o��"+RANK_D->query_respect(me)+"�F�A�ڨ��W�o�F��O�x�Įv�̰e����\n",this_player());
                message_vision("���A�]�����D������ΡA�{�b�e���A�աC\n",this_player());
                add("count",-1);
                ob=new("/clone/medicine/vegetable/moyao");
                ob->move(me);
        }
        else {
                message_vision("$N���W�e�h�A���ۤ��������I�U�A�θ̹y�ɫG��F�\�h�C\n",this_player());
        }
        return 1;
}