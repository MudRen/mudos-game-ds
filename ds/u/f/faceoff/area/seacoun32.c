#include <ansi.h>
// #include <room.h>
// �S�Ψ� DOOR. by cominging
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
�o�̬O�L�c�a�a������, �A�i�H�ݨ�����ǭ��פW�\
��۲��~�M��b������������, ��M�L�c�a���H�]�O����
�X��, �A���L���q�N��O�o�M�ӥ�... �A���M�o�{����
�W�����@���A���{�{�o��.....?
LONG
    );
        set("exits",([ "south":__DIR__"seacoun31",
]));
        set("item_desc",([
        "����" : "�A�o�{���פW���@�Ӫ����{�{���F��!\n",
        "�A��" : "�A�o�{�A���̸ˤF�\\�h��������...�����D��ԣ��?\n",
        "��������" : "�A�i�H�⥦��(take)�_��.\n",
]));
        set("no_clean_up",0); 
        set("light",1);
        delete_temp("long");
        delete_temp("take_tackle");
        setup();
} 

void init()
{
        add_action("do_take","take");
}
int do_take(string arg)
{
        object me, p;
        object room = environment(this_player());
        me = this_player();
        if( arg != "��������" ) return 0;
        if(room->query_temp("take_tackle") == 0)
        {
                message_vision(HIC"$N�q�A�����N�����������F�X�ӡC\n"NOR  ,me);
                p=new(__DIR__"obj/gold_tackle.c");
                p->move(this_player());
                room->set_temp("take_tackle",1);
                room->set_temp("long", @LONG
�o�̬O�L�c�a�a������, �A�i�H�ݨ�����ǭ��פW�\
��۲��~�M��b������������, ��M�L�c�a���H�]�O����
�X��, �A���L���q�N��O�o�M�ӥ�...
LONG
                );
                delete("item_desc");
                call_out("create", 600);
        }
        else
        {
                tell_object(me,HIR"���������H�a�����o�I\n"NOR);
        }
        return 1;
}

