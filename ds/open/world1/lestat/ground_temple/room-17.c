inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
���j���ж����A�\���F�U���U�˪��Z���M���ҡA��W���]���]�o
�X�����~�A�M�Ф������~�ۤ����M�A�b������������Z�����A�����z
�X�@����H�������P�A�ݨӳo�̪��D�H���O���q�H���C
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "south" : __DIR__"room-15",
        ]));
        set("objects",([
                   __DIR__"../npc/lieh_shen" : 1,
                 ]) );
        set("light",1);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}

