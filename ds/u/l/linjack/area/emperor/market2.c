#include <room.h>
inherit ROOM;
void create()
{
 set("short","����Q�E���a");
 set("long",@LONG
��ӳo��O�ӫ��F�_��Q���X�W�����㶰���a, ���̳\�h�ө�
�����~�ӷ����O�Ѧ��a�Ө�, �A�]��ݨ�\�h�ȫȩΦ���H�h�b�o
��D�F�D�誺. �@�릿��H�樫��������˳�, �o��O�����ɦ�,
���M�Sԣ�n�f, ���L���館�������A��B���ݨD. �֥�, �u, ��M
, �H��, �Ʀܲ�, �޵������`�Ψ쪺����A�b�o����R��.
LONG
    );
 set("exits",([ "northwest":__DIR__"market3",
                "north":__DIR__"center",
                "northeast":__DIR__"road6",
                "south":__DIR__"road2_2"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}