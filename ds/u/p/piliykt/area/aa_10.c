inherit ROOM;

void create()
{

set("short","�Z����");
set("long", @LONG
�A�@�Ө�o��, �N�Q�e�誺�C���j�~���h��F, �A�y�L�[��F�@�U,
�~���D�L�N�O�Z�������D�H, ���\�h���̤l�����L�ǲߪZ��, ���A������
�i�Q��L���ݪZ��.
LONG
);
set("world", "past");
set("light",1);
set("exits", ([                
"west" : __DIR__"aa_9.c", 

]));
set("objects",([
__DIR__"npc/master_1.c" : 1,
              ]) );

setup();
}

