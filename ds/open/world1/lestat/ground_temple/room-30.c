inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�A�Ө�F�@�Ӭ۷���������f�A�n�䤣���B���ߵۤ@�y���j����
�A�F�n�誺�D���h�����D�q�����̡A���_�����W�A������ۺ򨭸�
�����H���ݦu�ۡA�ݨӥ_�䪺�D���q�����a��j���峹�C
LONG
);
        set("exits", ([ /* sizeof() == 4 */
                  "south" : __DIR__"room-27",
                  "north" : __DIR__"room-32",
                  "southeast" : __DIR__"room-28",
                  "southwest" : __DIR__"room-26",
        ]));
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        setup();
}


