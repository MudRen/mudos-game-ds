inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�b�@���·t���A���򳣬ݤ���A���O�A�l��ı�o���H�b�ʵ��ۧA
�A�����H�ɳQ�ʵ����Pı�A���A�P��۷��w�A�u�Q�X�����}�o�̡C
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "south" : __DIR__"room-30",
        ]));
        set("objects",([
                   __DIR__"../npc/xu_kong" : 1,
                 ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        setup();
  load_object(__DIR__"temp");
}


