inherit ROOM;

void create()
{
        set("short", "�b�l���W");
        set("long", @LONG
�A�����b�@�y�۾��W�A�u�����y�᭻�A��M�s�A�A�p���v��A�a��p
���F�h�U���H�A�ò��x���A���������B�K�ײ��Y���B�s����Ӫ��A�w����
�������C�_���O���W���L�C�ȩ����A���n�U�h�N��F���f�A���_�h��`�J
��ߡC
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nb3",
  "southdown" : __DIR__"nb1",
]));
	set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
