inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�ж�����m�F�U���U�˪��A�˸򹢫~�A���׬O�k�ˤk�ˡA�Ѫ���
�������A�O�A���Tı�o�n�_�A�o��h�A�ˬO�ΨӰ�����Ϊ��C
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "southwest" : __DIR__"room-28",
        ]));
        set("objects",([
                   __DIR__"../npc/lei" : 1,
                 ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        setup();
}


