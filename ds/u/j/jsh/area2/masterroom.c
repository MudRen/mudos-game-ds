inherit ROOM;

void create()
{
        set("short", "�j�U");
        set("long", @LONG 
�o�̬O�j�Ӭ��D�H���@ [33m�u���L�v[0m���ж��A�ж������\�]�D�`��²��
�A���M��²��A����ڤW�@�w��²��A �����w���ǯS�O���F��ξ����A
�_��O�j�U�A�@���N�i�H�ݨ쩳�A�b�L�ɪ��`�B�A ���ػ����X�Ӫ��Pı 
�C
               �Aı�o�o�̤�@�몺�ж��٭n�N�@��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"room4",
]));
        set("objects", ([ /* sizeof() == 1*/
  __DIR__"goo" : 1,
]));      
        set("no_clean_up", 0);
        setup();

}

