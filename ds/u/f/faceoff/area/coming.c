#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�B�F�������s��");
        set("long",
"�o�̬O�B�F�������߳����A�Өө������O�\\�h�ȤH�A�ȤH��������\n"
"�U�غرڪ��H�̡A�B�F���O�j�N�L�W�ꪺ�����A���]���O�L�W�ꪺ����\n"
"�ҥH�֦��\\�h��O�������Z�x�M�N�x�A���ެO�b�L�W�ꪺ���@�Ӧa��A\n"
"�H�H���|���B�F�O�̱j���A�b�o���ٲ���@�عC���A�N�O��ۦ窫���i\n"
HIY"�j��(well)"NOR"�̡Ať���b�Q�Ѥ����|���n�d���Ʊ��o�͡A�b�������䦳�\\\n"
"�h�q���޶i���o�O�A�ߤW�N�|�I�_�ӷӫG�o����C\n"
        );
        set("exits", ([
  "south" : __DIR__"boo-lin2.c",
  "up" : __DIR__"survey.c",
  "east" : __DIR__"beast.c",
  "west" : __DIR__"bwest.c",
  "north" : __DIR__"bnorth.c",
]));
        set("light",1);
        set("item_desc",([
  "well" : HIC"�o�O�@�f�j���A�b��������`�`���p�Ĥl�b�����i�h�j�����C���C\n"NOR,
]));
        set("objects", ([
  __DIR__"npc/yuanlieh" : 1,
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        call_other("/obj/board/boo-lin_b.c","???");
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me,where;
        string a;
        me = this_player();
        where = load_object(__DIR__"well.c");

        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "in %s", a )!=1 )
                return notify_fail("���O�榡�G jump in <�a�I�W> .\n");
        if( a!="well" )
                return notify_fail("�A�n���쨺�̡H\n");

        message_vision("$N�`�l�@�f��A����䪺�H���D�A���A�M�ᨫ��F�j���ǡA\n"
                        +"���_���¦��s��÷�l���U�����F�h�C\n",me);
        call_out("flop",5,me,environment(me));
        me->move(where);
//      shout(HIB+me->name()+NOR+HIR"�ϺɦY�����O��s�D�R�ϩR�r�I\n"NOR);
//      write(HIR"�A�ϫl�j�ۡR" + arg + "\n"NOR);
        call_out("flop1",3,me,where);
        return 1;
}

int flop(object me,object a)
{
        tell_room(a,"�b"+me->name()+"���U�h���[����A�A���Gť��"+me->name()+"�@�Ǥp�p���j�T�q�j���]�X��\n",({ me }));
        return 1;
}
int flop1(object me,object a)
{
        tell_room(a,me->name()+"�q�W�誺���a�W���F�U�ӡA�P�A�����@�ΡC\n",({ me }));
        return 1;
}
