#include <ansi.h>

inherit ROOM;

void create()
{
   ::create() ;
   set ("short", "��ѧ���") ;
set ("long",
    "�o�̴N�O�����j�W�����d�A�۶Ǳq�o�X�h����A�Q�^�Y�]
���A�ӳo�̪��H�����y�ǵۤ@�Ӷǻ��A�۶ǳo�̴��g���c�@��
���b���y�^�A�Q�j���P�T�ʦL�b���A�Ӧb�L���W�ڻ����@�د�
�����_���A�S�Q��s�I���H���Q�@���s��......\n"



) ;
   set ("exits", ([
                    "north":__DIR__"desert1.c",
                    "south":__DIR__"infinite.c",
   ])  ) ;
        set("outdoors","desert");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

