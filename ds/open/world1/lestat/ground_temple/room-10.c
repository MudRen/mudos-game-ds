inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�b���m�����D���A�A����ı�o���H�b�ʵ��A�A���o�S�L�k�T�H�O
�_�u�����H�b�ʵ��A�A�F�䪺�ж����ǨӤ@�ǲӷL���n�T�A���G���H
�b���䬡�ʪ��ˤl�A�A�����h�ݤ@�U�C
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "east" : __DIR__"room-11",
                  "north" : __DIR__"room-14",
                  "south" : __DIR__"room-06",
        ]));
        set("light",0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}

