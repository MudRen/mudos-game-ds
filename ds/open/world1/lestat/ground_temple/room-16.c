inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�q�L�j�U����A�a�U�q���}�l�ܤp�ܯ��A�Ů�]�V�ӶV�V�B�A��
�䪺����}�l�X�{�t���⪺�����A�j���O���񪺩��h�I�t�K�q����q
�a�A�o�]��ܦa�U���V�ӶV�`�J�a���C
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "northwest" : __DIR__"room-20",
                  "southeast" : __DIR__"room-15",
        ]));
        set("objects",([
                   __DIR__"../npc/wood_monster" : 1,
                 ]) );
        set("light",0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}

