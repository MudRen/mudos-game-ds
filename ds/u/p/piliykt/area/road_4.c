inherit ROOM;

void create()
{

set("short","�j��");
set("long", @LONG
�A�����b�j��W, �o�̤H�n���m, �������s, ���x�D�Z.�ө�
���L���H�ܦh, ��Ǧ��\�h���Ы�, �ؿv���D�`�}�G.�b�A���k��
���@�ɺ}�G���j��H�a,���F��F�����s��.
LONG
);
set("outdoors", "desert");

set("exits", ([                
         "west" : __DIR__"road_3.c", 
         "enter": __DIR__"horse_2.c",       
         "east" : __DIR__"road_5.c",
   ]));

 setup();
}


