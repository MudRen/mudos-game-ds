inherit MOBROOM;

void create()
{
        set("short", "�a���������");
        set("long", @LONG
���ߦb�A���e���A�O�@�y���j���ťզ���A�����O�L�k�P�_��
��������A�����W���C���᯾�J�ۤ@�T�j���e�A�e�����@������
�C�A�C�L�˧ꪺ�Ԥh���b�P�c�]�����氫�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                   "north" : __DIR__"room-30",
                   "south" : __DIR__"room-22",
        ]));
        set("chance",80);
        set("mob_amount",3);
        set("mob_max",15);
        set("mob_object",({
           __DIR__"../npc/mascot_lion",
        }) );
        set("light",1);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}



