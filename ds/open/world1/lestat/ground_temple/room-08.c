inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�@�}�_�Ǫ��զ�����q�����ƨӡA�V���ۿN�J���A�N�׭��A�H��
�@�Ѳ��W���𮧡A�٦��ŷx�������A�{�l���w�B�P�B�P�s���A�A����
ı�o�Q������h�M����D���ӷ��C
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "west" : __DIR__"room-07",
                  "north" : __DIR__"room-12",
                  "south" : __DIR__"room-04",
        ]));
        set("light",0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}

