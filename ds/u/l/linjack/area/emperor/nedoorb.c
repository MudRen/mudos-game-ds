#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ӫ��������e");
 set("long",@LONG
�~�Ө�o, �N�o�{�H�s�H��, ��ӳo��N�O�t�v�W�ꪺ�ӫ�
�|�j��������, ���F�_�䪺�������e, �o��O�i�������g����,
�]�����|�������d, �o�w�g�����֨��ީx�L�b���Y�}�H��, �p�G
�Q�b�ӫ��@��, ���ȴN����a���o!
LONG
    );
 set("exits",([ "southwest":__DIR__"nedoor",
                "northeast":__DIR__"market3"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}