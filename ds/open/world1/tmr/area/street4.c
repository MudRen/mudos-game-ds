inherit ROOM;

void create()
{
        set("short", "�j��");
        set("long", @LONG
�A���b�@���H�ӤH�����j��W�A����N�O����̹��W���u�¤Ѽӡv�A
�Ӱ��T�h�A���e��ۨⰦ�j�۷�A���W���ۤ@�Ӫ��ة۵P�A�A���W�N�ݨ�
�G�Ӫ��ȤH���b�j�v���[�C�k��h�O�o�̳̤j�������Сu���H�����v�A��
��O�u�Ʊ��s���v���H�Ҹg�窺�A�ҥH�õL�d�p���h�@�áC���_�O�Ӥp�s
���A���n�O���j��C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"street5",
  "west" : __DIR__"hotel",
  "north" : __DIR__"square",
  "east" : __DIR__"bank",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/dog" : 1,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

