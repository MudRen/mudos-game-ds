#include <room.h>
inherit ROOM;
void create()
{
 set("short","�Z���Q�E���a");
 set("long",@LONG
��ӳo��O�ӫ��F�_��Q���X�W���Z�������a, ���̳\�h�ө�
�����~�ӷ����O�Ѧ��a�Ө�, �A�]��ݨ�\�h�ȫȩΦ���H�h�b�o
��D�F�D�誺. �o�����M�S���椰�򰪯Ū��_�M�_�C, �i�O�f�~��
��, ���q����H�|�Ϊ��Z���b�o��j���i�H���.
LONG
    );
 set("exits",([ "southwest":__DIR__"road8",
                "southeast":__DIR__"market2",
                "northeast":__DIR__"market1",
                "east":__DIR__"center"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}