// pray_bridge.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"��������"NOR);
        set("long",@LONG
  �o���Sù���������������q�o�̦V�訫�O�����C
�A�����b�@�Ӿ��W�A�V�U��h�O�Ӵ�A��ӯ����O
�ئb�򪺥������C����M�����p�ۨӤ��@��A�̭�
���۴X�������b��a�A�򭱤W�٦��\�h�p���n�b��
���ۥѦۦb���ˤl�O�H�����C
LONG
        );
        set("exits", ([/*sizeof=2*/
                "east"    : __DIR__"pray_st2",
                "west"    : __DIR__"pray_bd1",
                ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
