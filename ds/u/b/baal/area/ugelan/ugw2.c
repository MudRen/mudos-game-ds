#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", RED"�վB��������u�ƶ��n��"NOR);
        set("long", @LONG
��W���ۼƤ�����A�N���Y�Ӫ��O���q���A���Y����U
���ۤ@���ԺX�A���Y����Ǥκ��Y�U���@������A���W�J��
�u�ƶ��@�P�����O�G�@���Q�Ϥ����|�Ӱϰ쪺�޵P�A��|��
�ϰ���O��W�����P���L�O�A���Y���Y��������ǵۦU��F
�@�Ƥ��j�˦����s���Z�ҥH���˹��ΡC
LONG
        );
        set("exits", ([ 
                        "north": __DIR__"ugwcommand",
                        "south": __DIR__"ugw1",
"west": __DIR__"ugw3",
"east": __DIR__"ugw4",
            ]));
           set("item_desc",([
"�޵P���O" : "
�@�Ӭ޵P�Ϊ������O�A�Q�Ϥ����|���A���W�J�ۤ@�Ө�
�b�A�N��R�O�A�k�W�J�ۤ@���p�p���j�ѡA�N��k�ߡA
���U�h�O�@������������A�N��ε��A�̫�b�k�U�h��
�ۤ@����C�A�N��O�q�A�o�����O�N��F�c���u�ƶ���
�|�ӭn���G�R�O�B�ߪk�B�ε��B�ΤO�q�C\n",
"�ԺX" : "
�N��վB��������u�ƶ����ԺX�A��������A�W¸�ۤ@
���j�i���⤤�r���@���Ŧ��_�ۡC\n",
                 ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
                create_door("north","���","south",DOOR_CLOSED);
create_door("west","��O��","east",DOOR_CLOSED);

}

