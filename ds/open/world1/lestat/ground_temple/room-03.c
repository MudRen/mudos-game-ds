inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�ﭱ�ӨӪ��������A�V���ۦǹЩM�G�Ѫ����D�A�ݨӳo�ӿ��
�w�g�ܤ[�S���H�i�ӹL�F�A�j�����O�Q��誺�u�@���J���צb�~���F
�a�A�����D�o�j�Ǫ��a���٦�����Ⱦ��C
LONG
);
        set("exits", ([ /* sizeof() == 4 */
                  "south" : __DIR__"room-02",
                  "north" : __DIR__"room-05",
                  "northeast" : __DIR__"room-06",
                  "northwest" : __DIR__"room-04",
        ]));
        set("light",0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}
