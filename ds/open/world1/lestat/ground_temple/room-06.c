inherit MOBROOM;

void create()
{
        set("short", "�a���������");
        set("long", @LONG
�e�s���a�U�D���̡A���˴˪��Pı�M�G�A�����W�U�C�@�Ӥ�աA
�����q��B�j�i�Ӫ����A�N�B�B�a�A��[�W�K�޲�����^�A���M�X��
�ѹ��q�A�}��ȹL�A���]�H�Y�Q�����W���ͪ��Ҹɱ��C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                   "west" : __DIR__"room-05",
                   "north" : __DIR__"room-10",
                   "southwest" : __DIR__"room-03",
        ]));
        set("chance",80);
        set("mob_amount",3);
        set("mob_object",({
           __DIR__"../npc/sky_cat",
        }) );
        set("light",0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}

