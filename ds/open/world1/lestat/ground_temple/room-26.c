inherit MOBROOM;

void create()
{
        set("short", "�a���������");
        set("long", @LONG
���򤧫e���ؿv����A�ťզ⪺����W��۫C��⪺�ǲ��å���
���A�A�P�_�o�j���O���j�ɥN���j��r�A��N�X�G�w�g�S���H���o�o
��r�F�A�]���L�k�o���o�Ǥ�r���N�q�H�ξ�ӫؿv���ѨӡC
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                   "northeast" : __DIR__"room-30",
                   "southwest" : __DIR__"room-20",
                   "northwest" : __DIR__"room-29",
        ]));
        set("chance",80);
        set("mob_amount",3);
        set("mob_max",15);
        set("mob_object",({
           __DIR__"../npc/god_leopard",
        }) );
        set("light",1);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}



