#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED"�վB��������u�ƶ��n��"NOR);
        set("long", @LONG
�o�̬O�վB��������u�ƶ����n�ҡA���t����O��b��
�⪺��ģ�U���㶡�Τl�a�ӤF���t���𮧡A�㶡�Τl�R����
�Ѧ����B�֭��B�K���Ϊo�שҲV�X�����D�A�j�U��ǦU���@
��u�ƶ������o�����A������١A�O�H��ӥͬȡA�j�U���
���۬��Ƥ��֪��޵P�M���C�A�٦��X���N��u�ƶ����X�l��
�b��W�A�b��������ģ�U�Ϯg���f�H�����~�C
LONG
        );
        set("exits", ([ 
                        "north": __DIR__"ugw2",
                        "south": __DIR__"w1st3",
            ]));
           set("item_desc",([
"�ԺX" : "
�N��վB��������u�ƶ����ԺX�A��������A�W¸�ۤ@
���j�i���⤤�r���@���Ŧ��_�ۡC\n",
                 ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
}

