inherit ROOM;
void create()
{

set("short","�F�j��");
set("long", @LONG
�A�C�C������F�o��, ����������F�j��b�o�̵����F, �o����o��
����٭n�w�R�o�h�F, �Ӧ���h�O�������s���e�i, �ӦA���F�e�i�N�n�X
�F�����.
LONG
);
set("outdoors", "land");
set("exits", ([                
"east" : __DIR__"rr_5.c", 
"west" : __DIR__"rr_1.c", 
        ]));
set("objects",([
__DIR__"npc/guard_2.c" : 1,
       ]) );

 setup();
}


