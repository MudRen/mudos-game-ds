#include <room.h>
inherit ROOM;
void create()
{
 set("short","��L�����Y");
 set("long",@LONG
�A�b�o���L�����F�n�@�q�ɶ�, ���e�@��, �`��ݨ�F��L��
�X�f, ���T�y��. �o��w�g�������ݨ��T�Ӿ��ҩάO���H�b�樫,
�Aı�o�w�g�֨��F�V����F. ���F���i�H����U�s�����W.
LONG
    );
 set("exits",([ "east":__DIR__"mountroad1_2",
                "northwest":__DIR__"mountroad3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}