inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
����·t���a�D���A�u���X���ѹ��B�����b���ʡA���m���a�U�q
������[��o�N�M�A�Y�S���A���Ө�A�����w�o��i��w�g���X�ʦ~
�����H�ܤF�A�A���U���|�O���򪬪p�A���T�O�H��~�C
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "northeast" : __DIR__"room-24",
                  "southwest" : __DIR__"room-15",
        ]));
        set("objects",([
                   __DIR__"../npc/wood_monster" : 1,
                 ]) );
        set("light",0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}
