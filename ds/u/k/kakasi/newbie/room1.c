inherit ROOM;

void create()
{
        set("short", "�D�]�j��");
        set("long", @LONG
�A���b�@���H�ϵ}�֪��j��W�A���e��N�O���񹣦W���u�s��j�D�]�v�A
���Ӱ�4�h�A�����������i�Hť��ܦh���n�A�|�P���O �\�� �Ѿ� ���~�A�
�o�ӹD�]�ʤs�a���A�����q�R�A���Ƿ|���񹣦W�C 
���G�����~���n���b��A�D�]�CLONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"/open/world1/cominging/purple_sun/psin3",
  "north" : __DIR__"room2",
  ]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"beast" : 2,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

