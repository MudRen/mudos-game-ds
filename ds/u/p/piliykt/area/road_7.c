inherit ROOM;

void create()
{

set("short","�j��");
set("long", @LONG
�o�̬O�����s�����n��, �A���b�j��W�Pı�D�`�ΪA, �A�ݤF�ݤj��
,�~���D��D�ⰼ���W�F�OŢ, ��ӧA�����䦳�a�ʪ��, �O���q��,����
�ӵ�D�����{�{.���n��F�j��.
LONG
);
set("outdoors", "land");
set("light",2);
set("exits", ([                
        "south" : __DIR__"road_8.c", 
        "east"  : __DIR__"sex_1.c",
        "north" : __DIR__"road_6.c",
   ]));
set("objects",([
__DIR__"npc/dog1.c" : 1,
       ]) );

 setup();
}

