#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"�s���̹D-�_�f"NOR);
 set("long",@LONG
�s���̹D�b�o�̴N�����F, �A���e�u�ѤU�@���l��, ��
�s���̹D�쥻�b���ਤ�u�ݱo��@����t, �ϩ��b�����H��
�o�̴��g�O�g�Ӫ��D�n�~�|, �ӥu�����e���s���o�R�R��ť
....
LONG
    );
 set("exits",([    "south":__DIR__"ten26",
       "northwest":__DIR__"moon",
    ]));
set("no_clean_up",0);
set("outdoors","land");
set("item_desc",([
      "�s��" : CYN"�o�s�����M�~�k,�b���\\�W���@�w�{�ת��H���ӥi�H��(climb)���W�h\n"NOR,
]));

 setup();
}
void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me,where1,where2;
        string a;
      int x;
        me = this_player();
        where1 = load_object(__DIR__"ten28");
      where2= load_object(__DIR__"ten29");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("�A�n�������?\n");
        if( a!="�s��" )
                return notify_fail("�o�̨S���o�تF�赹�A��\n");
        message_vision(HIW"�u��$N�����P�P���b�s���W���D, ���M�@���ਭ���h�F�ܼv..?!\n"NOR,me);
       x = me->query_skill("dodge") + me->query("dex") + random(40);
       if ( me->query("level") >5 &&  x < 33 )
   {
      tell_object(me,HIR"�A���p�ߤ@�ӥ���, �^����s������!!\n"NOR);
        me->move(where2);
    }
     else
    {
      tell_object(me,HIW"�A�u�ۤs�����W�F�s��p!\n"NOR);
      me->move(where1);
    }
        return 1;
}



