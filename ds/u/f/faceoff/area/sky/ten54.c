#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"�d�����q"NOR);
 set("long",@LONG
�A�@�i�ӳo��, �N�P���������l, �@�M�����~�X�@��
�ǻ����d���A���ġA�v�T���@�P�гy�F�Q�U�j�s�A���b
�L�{���d���Z������Ӫ��_���~�A�޵o�F�ҿת��m �Q�U��
�Сn�A�]�����b�������^�����C�A�]�]�����ΤW�@���~�D
�����H�A����]�S��....
LONG
    );
 set("exits",([   "out":__DIR__"ten51",
    ]));
set("item_desc",([
        "����" : HIG"���Ϊ��������ӭ����^�b�W��....\n"NOR,
      "����" : HIG"�N�O�@�ӭ��㫧! �A�i�H�⥦���_��....(take)\n"NOR,
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
   if( a!="����" )
                return notify_fail("�A�����M�F��? �o�̨S���o�تF��!\n");
        if(room->query("take_leg") == 0)
        {
                message_vision(HIC"$N�N����q���ΤW���F�X��....�C\n"NOR  ,me);
                p=new("/u/f/faceoff/area/sky/eq/faceoff_mask.c");
                p->move(this_player());
                room->set("take_leg",1);
                delete("item_desc");
        }
        else
        {
                tell_object(me,HIR"�o�̪ŵL�@���I\n"NOR);
        }
        return 1;
}
