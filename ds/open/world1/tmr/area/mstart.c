inherit ROOM;

void create()
{
        set("short", "�s���F���f");
        set("long", @LONG
�s���O�o���񷥦��W�𪺡u�K�����v�A�����Ѯz�����ӭӬ����Z�N�A
�k�l�h�����ǹL�K�����Ať���a���������_�A�O�Ѥ@��u�K�����v�Ĥ�
�N�x���H�A�H�١u���j���v�����Ѥ�v���ҶǱ¡C���F�O�y�p�s���A��
��O�@�j���Цa�A�s���N�b�Цa�����ݡC
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ms1",
  "east" : __DIR__"square",
  "north" : __DIR__"post_office",
]));
	set("outdoors","land");
        set("no_clean_up", 0);

set("light",1);
        setup();
        replace_program(ROOM);
}
