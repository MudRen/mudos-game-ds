inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
���a�����H�ΰ�n�p�s�����e�A�ﭱ�ӨӪ��{û���A�c���F�@
�T�ť���ߪ����H�A�a�W�����ֶ��¥դT�⪺�~��A�i��O�Y�س��~
�ұ������A�o�̤j���O�e���~�ۧa�C
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "east" : __DIR__"room-22",
        ]));
        set("objects",([
                   __DIR__"../npc/tiger_man" : 2,
                 ]) );
        set("light",0);
        set("no_clean_up", 0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        setup();
}

