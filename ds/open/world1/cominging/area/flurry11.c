inherit MOBROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
�A�{�b�b���誺�U��A���ŤW�観�@��檺��r�A���L�g�L���B��
�R�ݦ��G�w�j�����P���A�A�u�������ݥX�X�檺��r�A�{�b�o�̬O�@�y
�p���A���������n�A�Ϊ��s�n�A�{�p���T���@�몺�nť�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"flurry17.c",
  "north" : __DIR__"flurry12.c",
  "east" : __DIR__"flurry16.c",
  "southup" : __DIR__"flurry10.c",
]));
        set("no_clean_up", 0);
        set("chance",40);
        set("outdoors","land");
        set("mob_amount",4);
        set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
}));
        setup();
}

