// Room34.c

inherit ROOM;

void create()
{
        set("short","�i���\\��j");
        set("long", @LONG
�Ѧa�|�b�ѤU�����󦳼ƦʡA�Ө䤤�̭��n����j����N����b
�`�몺�Ҧb�C�Ǥ���ۤQ�h�i�j��ȡA�ӥB���@�W�ѧB�b�����C�ӥ|
�P�G�m�o�@�Ф��V�A�N�M�j���@�ˡA�A�Q�j���O���e���ѧB�Ҿ�z��
�a�A��M�A�ߤ��@�_�A�ݨ�o�ѧB�����O�@�`���K�������K�����A��
�����D�`�H�i�H���_....�A�ߤ��Q�ۡA�i���\��j�G�M�O�ת����s��
�a�C

LONG
        );
        set("exits", ([
                "east": __DIR__"room35",
        ]));
        set("objects",([
//__DIR__"item/equip_shelf" :1,
__DIR__"item/weapon_box" :1, // 2006.5.30 add by whoami
//__DIR__"item/item_shelf" :1,
]));
        set("light",1);
        set("no_kill",1);
set("no_goto",1);
        setup();
        set("stroom",1);
}

