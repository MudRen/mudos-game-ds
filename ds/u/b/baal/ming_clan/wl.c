inherit ROOM;
void create()
{
 set("short","���p��");

 set("long",@LONG
�o�O���Цs�񨾨�B�Z���M�D�㪺�a��A�[�W�Y�㺡�ت�������
�Z���M�U�جé_���_�A�O�H���Ἲ�áA�o���O�ѭ��p�������H
�X�ͤJ�������묹�ͩR�ұo�Ӫ��A�ѩ�L�̪��V�O�A�[�W���Ъ�
�ε��A���Ф~�����ѳo�˪����N�C���䦳�H�b��z�[�W�����~�A
�M�޲z�C
LONG
    );
 set("exits",([ "up": __DIR__"saintming",
"east": __DIR__"darkfire",
    ]));
        set("no_kill",1);
        set("objects",([
__DIR__"item/eq_shelf" :1,
__DIR__"item/wp_shelf" :1,
__DIR__"item/item_shelf" :1,
]));
        set("light",1);
 setup();
        set("stroom",1);
}

