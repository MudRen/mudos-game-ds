#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�B�F������");
        set("long",@LONG
�o�̬O�B�F���������A�o�̪��n�����O�Hı�o���ǳ\�n���A���L�o
�]���Ǥk�l���s���n�]�ܮ��աA���O��k�l�ʧ����ۥs�n�Φ��F�۷�
���A�o�]���Ǥp�p���Ĥl�b�V�ӤH�ʶR�@�Ǧn�ܪ��e�}���M�n�Y����
�Ǥl�A�A�]�\�Q��p�ɩM�P��@�_�H�������ΡA�o�䪺���񦳤@�ǱM��
�c���`�ͬ��Ψ㪺�p�c�A�A�b���a���ϩ��ݨ�a�W���@�Ǥp�Ĥ��n��
����C
LONG
        );
        set("exits", ([
  "north" : __DIR__"boo-lin.c",
  "south" : __DIR__"boo-lin3.c",
]));
        set("item_desc",([
  "toy" : "�@�ǧA�p�ɭ����˱`�ʶR���A������A�O�A�Q��p�ɭԤѯu�L����\n���ΡA�A�i�H�յ۾�(pick)�ݬݡC\n",
  "����": "�@�ǧA�p�ɭ����˱`�ʶR���A������A�O�A�Q��p�ɭԤѯu�L����\n���ΡA�A�i�H�յ۾߬ݬݡC\n",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("chance",40);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
  __DIR__"npc/sparrow",
}) );
        setup();
}

void init()
{
        add_action("do_pick","pick");
}

int do_pick(string arg)
{
        object me,toy;
        me = this_player();
        toy = new(__DIR__"npc/obj/toy.c");
        if( !arg ) return 0;
        if( arg!="toy" && arg!="����" ) return 0;
if( query_temp("gettoy") )
{
    return 0;
}

        message_vision("$N�߰_�@�Ӫ���C\n",me);
        toy->move(me);
        set_temp("gettoy",1);
        this_object()->delete("item_desc");
        set("long",@LONG
�o�̬O�B�F���������A�o�̪��n�����O�Hı�o���ǳ\�����A���L�o
�]���Ǥk�l���s���n�]�ܮ��աA���O��k�l�ʧ����ۥs�n�Φ��F�۷�
���A�o�]���Ǥp�p���Ĥl�b�V�ӤH�ʶR�@�Ǧn�ܪ��K�}���M�n�Y����
�Ǥl�A�A�]�\�Q��p�ɩM�P��@�_�H�������ΡA�o�䪺���񦳤@�ǱM��
�c���`�ͬ��Ψ㪺�p�c�C
LONG
        );
        call_out("delay",180,this_object());
        return 1;
}

void delay(object room)
{
        delete_temp("gettoy");
        set("long",@LONG
�o�̬O�B�F���������A�o�̪��n�����O�Hı�o���ǳ\�����A���L�o
�]���Ǥk�l���s���n�]�ܮ��աA���O��k�l�ʧ����ۥs�n�Φ��F�۷�
���A�o�]���Ǥp�p���Ĥl�b�V�ӤH�ʶR�@�Ǧn�ܪ��K�}���M�n�Y����
�Ǥl�A�A�]�\�Q��p�ɩM�P��@�_�H�������ΡA�o�䪺���񦳤@�ǱM��
�c���`�ͬ��Ψ㪺�p�c�A�A�b���a���ϩ��ݨ�a�W���@�Ǥp�Ĥ��n��
����C
LONG
        );
        set("item_desc",([
  "toy" : "�@�ǧA�p�ɭ����˱`�ʶR���A������A�O�A�Q��p�ɭԤѯu�L����\n���ΡA�A�i�H�յ۾߬ݬݡC\n",
  "����" : "�@�ǧA�p�ɭ����˱`�ʶR���A������A�O�A�Q��p�ɭԤѯu�L����\n���ΡA�A�i�H�յ۾߬ݬݡC\n",
]));
        return;
}
