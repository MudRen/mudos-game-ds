inherit ROOM;

void create()
{
        set("short", "�B�F����");
        set("long", @LONG
�d�ӥd�h�d�ӥd�h�A�B�F�����̪��H���G��������������b�o�X 
�樾�㪺�u�Y���\�]���u�l�e�A�o�̪��ˬ[�W���ۤ@��S�@�󪺥��K
�������K�Ϋ~�A�s�a�կP���W���w�֥ҳ��O�L���ǧ@�C

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"store5",
  "south" : __DIR__"store4",  
])); 
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"storeman6" : 1, 
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

