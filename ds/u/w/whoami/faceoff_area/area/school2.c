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
 set("exits",([ "west":"/u/f/faceoff/school1.c",
                "up":"/u/f/faceoff/school3.c",
    ]));
 set("item_desc",([
        "wood":"�A�ݤF�ݳo�ڤ��Y, �o�{�I���O����, �W���g��: �԰��ޥ�, ....
�z! �᭱���r�ݤ��M�F....����O? ��F, �H�a���O���߸۫h�F��? �άݬݦ�
��(god)�i���i�H���A�a! .\n",
        "god":"�A�ݤF�ݴ���, �ߤ����T��ë�ۤv��DS�@�����Q, ���M, ��! ���@�n, 
�@���ѱ��F�U��.....\n",
        "book":"..�o���ѬO�n�ЧA�p��԰�, �]�O�ѯ��Q�A�ۤ߷P�ʦӱ��U����..
�Ʊ�A�n�n�ݤ@�U, ����, �`�N�ݳo�̪����O(flowers)�̭����@������, �復�Ukill
���O, ���N�O�԰�����p, �԰��e������considerŲ�w�@�U�ĤH, �A�}��, ���U�@����
�}�`����O? �A����|��@�Ӧ�����J�����a��....�䤤�@�ӬO�ͩR����, �@�ӬO��
�`����, �o���p�A, ���Ӫ��D�n�����@�ӧa!? �ϥ����F�A�չ�....\n",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}