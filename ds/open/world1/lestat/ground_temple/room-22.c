inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
����W���ǲ���r�즹�����A���W���C���å��~�]�����ܲH�A
���즹���G�w�g��F���Y�A�n���n�A�h�[��@�U�A�N�ݧA�ۤv���P
�_�F�C
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "east" : __DIR__"room-23",
                  "north" : __DIR__"room-27",
                  "west" : __DIR__"room-21", 
                  "south":"/open/world1/jangshow/flame_area/room",
        ]));
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        setup();
}

