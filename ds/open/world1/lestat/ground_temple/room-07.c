inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�N�ɪ�����A�|���@���l�šA�׭����H�ۥզ⪺�ϡA��¶�L�ڦb
�o�өж��A�����W����ۤ@���s�ަb�N�ۡA���z�F�F���A�A�f����
�y��}��F�C
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "east" : __DIR__"room-08",
        ]));
        set("objects",([
                   __DIR__"../npc/gui" : 1,
                 ]) );
        set("light",1);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}

