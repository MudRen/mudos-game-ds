#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���į��q"NOR);
 set("long",@LONG
�A�@�i�ӳo��, �N�P���������l, �@�M�����~�X�@��
��^���, �o��²���O���˪�����b���ˤF, �u�����Ϋe��
�Ⱖ�C�˪������O����G��, �����Ϯg�ۯ��ΤW���W��....
LONG
    );
 set("exits",([   "out":__DIR__"ten39",
    ]));
 set("objects", ([    __DIR__"npc/star_old_man" : 1,
]));

set("item_desc",([
        "�W��" : HIG"�A���W���@��, �o�{���@�ӻL�����������Ϯg���....\n"NOR,
      "�L������" : HIG"�A�A�a��@��, �o�ڥ��N�O�@���@�L��! �⥦��(take)�_�Ӥ]���|���H�o�{�a....\n"NOR,
]));
 set("no_clean_up",0);
 set("light",1);
 setup();
}

void init()
{
        add_action("do_take","take");
}
int do_take(string arg)
{
        object me, p;
       string a;
        object room = environment(this_player());
        me = this_player();
            if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("���O�榡�G take <���~> .\n");
        if( a!="�L������" )
                return notify_fail("�A�����M�F��? �o�̨S���o�تF��!\n");
        if(room->query("take_leg") == 0)
        {
                message_vision(HIC"$N�@�ӭ���, �N�@�L�q�W�������F�X��....�C\n"NOR  ,me);
                p=new(__DIR__"obj/baal_leg.c");
                p->move(this_player());
                room->set("take_leg",1);
                call_out("reborn",3600);
                room->set("long", @LONG
�A�@�i�ӳo��, �N�P���������l, �@�M�����~�X�@��
��^���, �o��²���O���˪�����b���ˤF, �u�����Ϋe��
�Ⱖ�C�˪������O����G��.
LONG
                );
                delete("item_desc");
        }
        else
        {
                tell_object(me,HIR"�o�̪ŵL�@���I\n"NOR);
        }
        return 1;
}

void reborn()
{
     this_object()->delete("take_leg");
}

