#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�۴Y���Y"NOR);

 set("long",@LONG
�A���̵ۤ߸̪��E��, ����F�۴Y�����Y, �o�O�V�a��۴Y���Y, �V
�O���G, �A�o�ɤߤ��w�L����`�Ȫ��Pı, �A�u�Q���}�o�ӥj�ѱЬ�����
������, �A�p�ߪ�����۴Y���Y, ���Y�����@��, �u���èS���A�Q������
�o���M, �]�S���T�B�@�^, ���B�@�諸�Y�K���u, �A�ݨ�@�Ӫſ�������
��, ������ۤ@�ӥۻO, ���X�ӤH�b�ۻO�e�����D�b������...
LONG
    );
 set("exits",([ "north":__DIR__"guild", 
                "west":__DIR__"birdpilla7",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

