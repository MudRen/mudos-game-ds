// Center.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIY"
 ������������ � �      
 �x" HIG"�����s��" HIY"�x 
 ������������
"NOR);
         set("long",@LONG
  �o�̬O�Sù���������s���A������ߵۥj�ɮ����
�w�������Eù�ǡ����ɹ�(statue)�A���Ӫ��������
��L�q�ȤT���C�o���٩�ۤ@�ӧG�i��(board)�C
LONG
        );
        set("item_desc", ([
             "statue": "�o�O�j�ɮ�����w�������Eù�ǡ����ɹ��C\n",
              "board" : "�o�Oboard�����L�ݼˤl����g�F�F��board�C\n",

          ]) );
        set("exits", ([/*sizeof=4*/
                "up":"/u/s/shrick/workroom.c" ,
                "east"    : __DIR__"memo1",
                "north"    : __DIR__"kain_n1",
                "south"    : __DIR__"crossd",
 ]) );

        set("outdoors","workroom.c");
}

