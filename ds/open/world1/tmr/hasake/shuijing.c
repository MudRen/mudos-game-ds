// shuijing.c
inherit ROOM;

void create()
{
        set("short", "���फ");
        set("long", @LONG
�s�C�U����O�����@�����फ�A�O�����̪������C���x�W���@�Ӥ�M
�M�Ѥf������H�ܤ��C���䦳�@�ӥѤH��ʪ������A����q�o�̤@���s��
�F�F�䪺���\�C
LONG);
        set("exits", ([
//                "eastup" : __DIR__"caochang",
                "southwest" : __DIR__"room-su",
                "northeast" : __DIR__"pmchang",                
        ]));
         set("objects", ([
                __DIR__"obj/hamigua" : 2
        ]));
        setup();
}
