// File: /d/mist_forest/big_tree.c
// Updated by tmr (Sat May 18 12:20:14 2002)

inherit ROOM;

void create()
{
          set("short", "�����W���j��");
          set("long", @LONG
�A�����b�@�ʤ����W���j��e�A�|�P���G���ۤ@�h�h�@�p�������A�}
�}���D�N���Ĥ��Y�A�b�çN���Ů𤤡A���G���@�����s���M�M�n�ǨӡA��
���٦��֫ݦb�o��C
LONG
          );
          set("exits", ([ /* 1 element(s) */
                "south" : __DIR__"map_1_1",
        ]));
	set("detail",([
                "�j��":"�A���Y��F�j��W���@�ھ�K�A���G�����H�b�W�����ΡC\n",
                "�H" : "������h�ݤ��M����ԣ�˨�A�A���T�ߥͤ���u��L�q�j��W�n�U���@�ӲM���v�C\n", // add by -Acme-
        ]));
          set("outdoors", "forest");

        setup();
}

int quest_ok=1;

void reset()
{
        ::reset();
        quest_ok=1; //�S��Ѱg�F
}

void init()
{
        ::init();
        add_action("do_shake","shake");
}
int do_shake(string arg)
{
        object me=this_player();
        object ob;
        if(!arg || arg!="�j��") return 0;
        if( !quest_ok
        || objectp(ob=present("drunk evil monster" ) ) ) {
                message_vision("$N�ϤO�a�n�F�n��F�A���O���F�X���������U�A�N����Ƥ]�S���F�C\n",me);
        
        } else {
                ob=new(__DIR__"npc/drunk-evil-monster");        
                message_vision("$N�ϤO�a�n�F�n��F�A���G�W�Y�����H�P�N�@�n�L�F�U�ӡC\n",me);
                quest_ok=0;
		ob->move(this_object());
                ob->do_chat("�ܾK���]�~���r�@�n�A���G�O�L�k�F�C\n");
        }
        return 1;
}
