inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�޲����j�N��r�̵M�躡�b�|�P������W�A�Ҵ��o�����~�o�ѲM
����ন�t����A�ٱa�۰}�}����{���A��өP����W��B�O�@�y
�y�����A�ݨӳo�̴��g�o�ͫܿE�P���԰�������C
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "southeast" : __DIR__"room-26",
        ]));
        set("objects",([
                   __DIR__"../npc/yuan" : 1,
                 ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        setup();
}


