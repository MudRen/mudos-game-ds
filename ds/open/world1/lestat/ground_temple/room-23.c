inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
[ �K�K�K ...]���s�n�j���b�|�P�A���j���ж�����B���O���Y�H��
�A�U�ث��ժ��H�����ݮݦp�͡A�B�j�p�N��u�H�@��A���O�H�_�Ǫ�
�O�A�o�ǥ��Y�H�����y�W���S�X���߸U���������C
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "west" : __DIR__"room-22",
        ]));
        set("objects",([
                   __DIR__"../npc/stone_bird" : 1,
                 ]) );
        set("light",0);
        set("no_clean_up", 0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        setup();
}

