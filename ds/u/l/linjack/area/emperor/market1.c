#include <room.h>
inherit ROOM;
void create()
{
 set("short","���f�Q�E���a");
 set("long",@LONG
��ӳo��O�ӫ��F�_��Q���X�W�����f�����a, ���̳\�h�ө�
�����~�ӷ����O�Ѧ��a�Ө�, �A�]��ݨ�\�h�ȫȩΦ���H�h�b�o
��D�F�D�誺. ���L�o��檺�j���O�ͬ����ݫ~, �����M��, �@��
�Ī�, �ħ�, ���, �M�@�����C���K���F��, �b�o��j���R�o��,
�ӥB�ٺ�K�y, ���O�n�Ʈe�����Q�O�H�m��, �]���n�R�u��������
�~�γ\�b�o��O�䤣�쪺.
LONG
    );
 set("exits",([ "southwest":__DIR__"market3",
                "south":__DIR__"center",
                "southeast":__DIR__"road6"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}