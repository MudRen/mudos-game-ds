inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�V�V��񤺳��i�J�A�Vı�o�_�ǡA�|�P���ؿv����P�J�f�B���j
�맹�����P�A�ťզ⪺����W��۳\�h�_�Ǫ��᯾�A���O�@�ؤ�r�A
�������~�ٴ��o�۫C��⪺�å��A���ѤF�ө��C
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "west" : __DIR__"room-19",
                  "northeast" : __DIR__"room-26",
                  "southeast" : __DIR__"room-16",
        ]));
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        setup();
}
