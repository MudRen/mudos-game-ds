inherit ROOM;
void create()
{
        set("short", "�y�����n��");
        set("long",@LONG
�o�̬O�y��������D�A���F��O�@�a�������A�ѩ�y�����a���ҥH
�s�A�������e�����o�A�]�����a�����A�Ʋz�]�O�Q���D�W���A�`�`���H
�j�ѻ����Ӧ��ɨ��@�f�A�ƦܬӫǤ]���H�R�n�󦹡A���W�`�������Ү�
�۷s�A����h�浹���̨ӧ@�Ʋz�A�]��O�y�����g�٨ӷ��F�C
LONG
        );
        set("exits", ([
  "north" : __DIR__"po3",
  "south" : __DIR__"po1",
  "east"  : __DIR__"po2e",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}


