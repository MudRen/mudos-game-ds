inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�쥻�e�s���a�U�q�D�b�o��Q���_�F�A�Y������P���۰ﺡ�F
��ӳq���A���F��_�観�@�Ӥp�p���_�ؤ��~�A�N�S����L���X���F
�A�����_�ح�n�i�H���@�ӤH�q�L�A�j���O���e�ӱ��I���H�Ҷ}�o��
�C
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "west" : __DIR__"room-13",
                  "northwest" : __DIR__"room-15",
                  "south" : __DIR__"room-10",
        ]));
        set("objects",([
                   __DIR__"../npc/air_flame" : 1,
                 ]) );
        set("light",0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}

