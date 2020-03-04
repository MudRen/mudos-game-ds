#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�˪ŮѰ|"NOR);

 set("long",@LONG
�A���i�F�t�@���ж�, �o�{�o�̬O�@�B�Ť��x�|, ��B���y�᭻, 
�A�ݨ쪺��c��M������P, �Ѧ��i�H�ݥX�o�̦��G�S���|�u����, 
�A�A�J�Ӥ@��, �o�{�b���O(flowers)���@�ڬ�_�����Y(wood)��M
�g�F�Ǧr, �A�@�Q�F�Q.... ��F, ���ݬݧa....
LONG
    );
 set("exits",([ "west":__DIR__"school1.c",
                "up":__DIR__"school3.c",
    ]));
 set("item_desc",([
        "wood":"�A�ݤF�ݳo�ڤ��Y, �o�{�I���O����, �W���g��: �԰��ޥ�, ....
�z! �᭱���r�ݤ��M�F....����O? ��F, �H�a���O���߸۫h�F��? �άݬݦ�
��(god)�i���i�H���A�a! .\n",
        "god":"�A�ݤF�ݴ���, �ߤ����T��ë�ۤv��DS�@�����Q, ���M, ��! ���@�n, 
�@����(book)���F�U��.....\n",
        "book":"..�o���ѬO�n�ЧA�p��԰�, �]�O�ѯ��Q�A�ۤ߷P�ʦӱ��U����..
�Ʊ�A�n�n�ݤ@�U. �����U search flowers �o�ӫ��O. �|�]�X�@������, �復�Ukill
���O, ���N�O�԰�����p, �԰��e������considerŲ�w�@�U�ĤH, �A�}��, ���U�@����
�}�`����O? �A����|��@�Ӧ�����J�����a��....�䤤�@�ӬO�ͩR����, �@�ӬO��
�`����, �o���p�A, ���Ӫ��D�n�����@�ӧa!?�ϥ����F�A�չ�...., ��F, �����ĤH��
���n�ѰO�^�m(sac)�L������(corpse)��!���i�O�m�O�H�������H�������...\n",
    ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}
void init()
{
        add_action("do_search","search");
}
int do_search(string arg)
{
        object me;
        object butterfly;
        me=this_player();
        if(arg != "flowers") return 0;
	if(me->query_temp("find_butter")) return notify_fail("�A�J�Ӫ���F����O, ���򳣨S���C\n");
	if(!me->query_temp("find_butter"))
	{
        	message_vision("$N�J�Ӫ��b���O���M��F��, ���O����M���X�@���p�����C\n\n",me);
		butterfly=new(__DIR__"npc/butterfly.c");
		butterfly->move(__DIR__"school2.c");
		me->set_temp("find_butter",1);
		return 1;
	}
}
