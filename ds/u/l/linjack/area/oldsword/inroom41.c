#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ư�D���");
 set("long",@LONG
���M�V����D���ɬO�ܥ�����H, ���O�N��O�M�ư�D
����Ǥ]�O�j�Ө�Ӥj�U���Z��, ���Ӥ�����o��D�ä��O
�ܥ~�V. �ư�D�ж����𱾤F�i��, �W���g�ۡu�p�p�e�աv
�|�Ӥj�r, ���S���g�O���D��, �]�S������S���׹�, �N
�u���o�|�Ӷ��K�����r, �����D������t�N.
LONG
    );
 set("exits",([ "south":__DIR__"inroom40",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
