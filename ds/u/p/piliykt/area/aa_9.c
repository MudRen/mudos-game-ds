inherit ROOM;

void create()
{

set("short","�m�Z��");
set("long", @LONG
�A�Ө�F�o�̤~�o�{���ӳo�̬O�m�Z��, �o�̬O������O�j������
���ҧ�ꪺ�ӤH�M�ݤ��@�ðV�m���a��, �A�B�B�i���o�̦��\�h���@�ç�
�l�A�o�m�ߪZ��.
LONG
);
set("world", "past");
set("light",0);
set("exits", ([                

"west" : __DIR__"aa_5.c", 
"east" : __DIR__"aa_10.c", 
]));
set("objects",([
__DIR__"npc/trainee1" : 3,
              ]) );

setup();
}

