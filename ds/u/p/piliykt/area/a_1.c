inherit ROOM;

void create()
{

set("short","�j�U");
set("long", @LONG
�o�̬O���������j�U, �|�P��W���F�\�h�W�e, �M�Ѫk�ֵ�, ���e��
�������O�����B��, �L����ǳ����@�ëO�@�ۥL, �A�ݥL�����۳B�z�ư�
�Kı�o�O�h���Z�L�n�F.
LONG
);
set("world", "past");
set("light",1);
set("exits", ([                

"south" : __DIR__"aa_3.c",
]));
set("objects",([
__DIR__"npc/pikemaster.c" : 1,
__DIR__"npc/axemaster.c" : 1,
__DIR__"npc/blademaster.c" : 1,


              ]) );

setup();
}

