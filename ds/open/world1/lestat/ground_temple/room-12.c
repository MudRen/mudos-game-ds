inherit MOBROOM;

void create()
{
        set("short", "�a���������");
        set("long", @LONG
��өж���B�O�_���ݾ��A���۪L�ߡA��M�O�g�L�@�ǤѨa�ܰ�
�A�ж����j���ۤ@�Ѹ{û���A���ɱq���K�B�ǨӪ��C�q�n�A�[�W��B
�����u�\����A���������o�̦��Ǥ��r���ͪ��s�b�C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                   "east" : __DIR__"room-13",
                   "south" : __DIR__"room-08",
                   "northeast" : __DIR__"room-15",
        ]));
        set("chance",80);
        set("mob_amount",3);
        set("mob_max",15);
        set("mob_object",({
           __DIR__"../npc/saint_wolf",
        }) );
        set("light",0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}


