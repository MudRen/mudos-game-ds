inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�ǵۧA���W�����ҵo�X���L�z���~�A�b�o�º������a�U��񤤡A
�V�O�a�����ۡA�j����W���j�۶���䦨������A�����F��⪺�a��
�A���ɺ��X���a�U���u�A�e�s���g�c���c�����H�Ĭ��[��C
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "east" : __DIR__"room-05",
                  "north" : __DIR__"room-08",
                  "southeast" : __DIR__"room-03",
        ]));
        set("objects",([
                   __DIR__"../npc/pf_demon" : 2,
                 ]) );
        set("light",0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}
