#include <room.h>
inherit ROOM;
void create()
{
 set("short","��^�j�Y");
 set("long",@LONG
�A�w�g����F��^�^�Y�̩��F, �}�U����^�������I�i�F�Фg
����, �|�P���W�]�����X�{�F�@�Ǫ��O���, �A���X�f��h�o�{�~
�����G�O�V���󪺫�s? ���L�A�{�b�~�oı�X�f���F�|�W���~, �n
�X�h���G���Ӯe��....
LONG
    );
 set("exits",([
               "south":__DIR__"hall2",
               "north":__DIR__"mount11",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
