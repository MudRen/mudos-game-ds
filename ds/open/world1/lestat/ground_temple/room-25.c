inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�C��⪺�޲��᯾���¨躡�|�P������A���F�᯾���~�A�٦h�F
�@�ǽ������ϧΡA�q���ݨӡA�ϧΤ����t�F�\�h�H�Ϊ��yø�A�ݤ[�F
����H�Φn���ʤF�_�ӡA���b���۩_�Ǫ��R�СC
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "west" : __DIR__"room-24",
        ]));
        set("objects",([
                   __DIR__"../npc/cha_na" : 1,
                 ]) );
        set("light",1);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}

