inherit ROOM;

void create()
{
        set("short", "�j�U");
        set("long", @LONG 
�o�̬O�j�Ӭ��D�H���@ [36m�u�p�s�k�v[0m ���ж��A�b�o�ж������W��A���@�
�����Q�ؤK�o���ʳ�÷�A�ڻ��p�s�k��ı  �𮧸�m�\�A���O�b�o��������
÷�l�W�A���\�y�ڡA���i���� �C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"room4",
]));
        set("objects", ([ /* sizeof() == 1*/
  __DIR__"dragongirl" : 1,
]));      
        set("no_clean_up", 0);
        setup();

}

