inherit ROOM;

void create()
{
        set( "short", "�a���}��") ;
        set( "long", @LONG
���˴˪��𮧤@���q�e�誺�q�D����ӡA�����}�}�A�����ۦU��
�_�Ǫ��n���A���H�򰩮��M�A�ߤ����ǹ��B�A�Ӥ��|�O�I�W�n�S�̤F
�a�H
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "up" : __DIR__"room-51",
                  "north" : __DIR__"room-34",
        ]));
        set("light",0);
        set("no_clean_up", 0);
        
        setup();
}


