#include <room.h>
inherit ROOM;
void create()
{
 set("short","�Ѿ�");
 set("long",@LONG
�A�q�L�F������, �Ө�F�Ѿ��W. �A���׫��@��, �N�ݱo��
�榰�[�Ǩ�y�G, ���M�A�P�@�Ӱ���, �q���a����, �i�H�N��ӦV
���s���ǤJ�A���G����, �A���M�o�{, ��ӦV����O�r�J�C�s����
��, �C�s�W���@���q���s�p, �W���ݰ_�Ӫ����|�g.

LONG
    );
 set("exits",(["south":__DIR__"inroom35",
               "north":__DIR__"inroom37",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
